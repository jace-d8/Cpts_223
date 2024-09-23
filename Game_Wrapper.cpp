//
// Created by Jace Dunn on 9/18/24.
//

#include "Game_Wrapper.h"

Game_Wrapper::Game_Wrapper(Linked_List<string , string>* cmd_list, ArrayNode<string, int>* user)
{
	do
	{
		cout << "How many questions could you like to try?(5-30): ";
		cin >> _question_count;
	}while(_question_count > 30 || _question_count < 5);
	run_game(cmd_list, user);

}

void Game_Wrapper::run_game(Linked_List<string , string>* cmd_list, ArrayNode<string, int>* user)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<int> questions(30); // going to use random.python for this bit
	for (int i = 0; i < 30; ++i)
	{
		questions[i] = i + 1;
	}

	std::shuffle(questions.begin(), questions.end(), gen);

	for (int i = 0; i < _question_count; ++i)
	{
		_answer = questions.back();
		questions.pop_back();

		std::shuffle(questions.begin(), questions.end(), gen);
		_c2 = questions[0];
		_c3 = questions[1];
		get_questions(cmd_list);
		display_questions(cmd_list, user);
	}
}

void Game_Wrapper::get_questions(Linked_List<string , string>* cmd_list)
{
	const Node<string, string>* tmp = cmd_list->get_head();
	for (int i = 0; i < _answer && tmp != nullptr; ++i)
	{
		tmp = tmp->get_next();
	}
	if (tmp != nullptr)
	{
		_cmd = tmp->get_command();
		_correct_choice = tmp->get_description();
	}

	// Reset head for choice 2
	tmp = cmd_list->get_head();
	for (int i = 0; i < _c2; ++i)
	{
		tmp = tmp->get_next();
	}
	if (tmp != nullptr)
	{
		_choice2 = tmp->get_description();
	}

	// Reset head for choice 3
	tmp = cmd_list->get_head();
	for (int i = 0; i < _c3; ++i)
	{
		tmp = tmp->get_next();
	}
	if (tmp != nullptr)
	{
		_choice3 = tmp->get_description();
	}
}

void Game_Wrapper::display_questions(Linked_List<string , string>* cmd_list, ArrayNode<string, int>* user)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int selection;
	vector<string> choices = {_correct_choice, _choice2, _choice3};
	cout << "Command: " << _cmd << endl;
	std::shuffle(choices.begin(), choices.end(), gen);
	for (int i = 0; i < choices.size(); ++i)
	{
		cout << i + 1 << ". " << choices[i] << endl;
	}
	do
	{
		cout << "What is your selection: " << endl;
		cin >> selection;
	}while(selection > 3 || selection < 1);

	if (choices[selection - 1] == _correct_choice)
	{
		cout << "One point added!" << endl;
		user->set_score(user->get_score() + 1);

	}else
	{
		cout << "One point removed!" << endl;
		user->set_score(user->get_score() - 1);
	}
	cout << "Your point total is: " << user->get_score() << endl;

}