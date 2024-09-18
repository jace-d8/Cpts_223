//
// Created by Jace Dunn on 9/18/24.
//

#include "Game_Wrapper.h"

Game_Wrapper::Game_Wrapper(Linked_List<string , string>* cmd_list)
{
	do
	{
		cout << "How many questions could you like to try?(5-30): ";
		cin >> questionCount;
	}while(questionCount > 30 || questionCount < 5);
	run_game();

}

void Game_Wrapper::run_game(Linked_List<string , string>* cmd_list)
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::vector<int> questions(30); // going to use random.python for this bit
	std::uniform_int_distribution<> distrib(0, questionCount - 1);
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
	}
}

void Game_Wrapper::get_questions(Linked_List<string , string>* cmd_list)
{
	Node<string, string>* tmp = cmd_list->get_head();
	for (int i = 0; i < answer; ++i)
	{
		tmp = tmp->get_next();
	}
	cout << tmp->get_command() << endl;
	tmp = cmd_list->get_head();
	for (int i = 0; i < c2; ++i)
	{
		tmp = tmp->get_next();
	}
	cout << tmp->get_description() << endl;
	tmp = cmd_list->get_head();
	for (int i = 0; i < c3; ++i)
	{
		tmp = tmp->get_next();
	}
}
