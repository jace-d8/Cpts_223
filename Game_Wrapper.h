//
// Created by Jace Dunn on 9/18/24.
//

#ifndef GAME_WRAPPER_H
#define GAME_WRAPPER_H
#include <iostream>
#include <vector>
#include <random>

#include "Array.h"
#include "Linked_List.h"
using namespace std;


class Game_Wrapper {

public:
	Game_Wrapper(Linked_List<string , string>* cmd_list, ArrayNode<string, int>* user);
	void run_game(Linked_List<string , string>* cmd_list, ArrayNode<string, int>* user);
	void get_questions(Linked_List<string , string>* cmd_list);
	void display_questions(Linked_List<string , string>* cmd_list, ArrayNode<string, int>* user);

private:
	int questionCount = 5;
	int answer = 0, c2 = 0, c3 = 0;
	string cmd, correctChoice, choice2, choice3;
};



#endif //GAME_WRAPPER_H
