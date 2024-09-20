//
// Created by Jace Dunn on 9/18/24.
//

#include "Game_Wrapper.h"

Game_Wrapper::Game_Wrapper(Linked_List<string , string>* cmd_list, Array<string, int>* profiles)
{
	do
	{
		cout << "How many questions could you like to try?(5-30): ";
		cin >> questionCount;
	}while(questionCount > 30 || questionCount < 5);
	run_game(cmd_list, profiles);

}

void Game_Wrapper::run_game(Linked_List<string , string>* cmd_list, Array<string, int>* profiles)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::vector<int> questions(30); // going to use random.python for this bit
	for (int i = 0; i < 30; ++i)
	{
		questions[i] = i + 1;
	}

	std::shuffle(questions.begin(), questions.end(), gen);

	for (int i = 0; i < questionCount; ++i)
	{
		answer = questions.back();
		questions.pop_back();

		std::shuffle(questions.begin(), questions.end(), gen);
		c2 = questions[0];
		c3 = questions[1];
		get_questions(cmd_list, profiles);
		display_questions(cmd_list, profiles);
	}
}

void Game_Wrapper::get_questions(Linked_List<string , string>* cmd_list, Array<string, int>* profiles)
{
	Node<string, string>* tmp = cmd_list->get_head();
	for (int i = 0; i < answer; ++i)
	{
		tmp = tmp->get_next();
	}
	cmd = tmp->get_command();
	correctChoice = tmp->get_description();
	tmp = cmd_list->get_head();
	for (int i = 0; i < c2; ++i)
	{
		tmp = tmp->get_next();
	}
	choice2 = tmp->get_description();
	tmp = cmd_list->get_head();
	for (int i = 0; i < c3; ++i)
	{
		tmp = tmp->get_next();
	}
	choice3 = tmp->get_description();
}

void Game_Wrapper::display_questions(Linked_List<string , string>* cmd_list, Array<string, int>* profiles)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int selection;
	// here
	vector<string> choices = {correctChoice, choice2, choice3};
	cout << "Command: " << cmd << endl;
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

	if (choices[selection - 1] == correctChoice)
	{
		cout << "One point added!" << endl;

	}else
	{
		cout << "One point removed!" << endl;
	}
}