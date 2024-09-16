/*
ADVANTAGES/DISADVANTAGES LINKED LIST
Advantage -
Disadvantage -
ADVANTAGES/DISADVANTAGES ARRAY
Advantage -
Disadvantage -
*/

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "Linked_List.h"

void populate(Linked_List<string, string> *mainlist) // Read CSV and input data into a linked list
{
    mainlist->open_file("commands.csv");
    mainlist->upload_file();
    mainlist->close_file();
}

int main()
{
    Linked_List<string, string> cmd_list;
    populate(&cmd_list);
    cmd_list.printList();

    string userName, newCommandToAdd, oldCommandTodelete;
    int questionCount = 0;

    int selection;
    while (true)
    {
        cout << "Please select an option listed below:\n";
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add"
        "Command\n5. Remove Command\n6. Exit\n";
        cout << "Your selection: ";
        cin >> selection;
        if (cin.fail()) // the input is not an integer
        {
            cout << "Your selection is invalid. Please select again." << endl;
            cout <<
            "=============================================================================" <<
            endl << endl;
            cin.clear();
            cin.ignore();
        }
        else
        {
            switch (selection)
            {
                case 1: // Game Rules
                {
                    cout << "================================= Game Rule"
                    "===================================" << endl;
                    cout << "This is a matching game \"2\" where you will be"
                    "given a linux command and have to match the cmd with its description.\n";
                    cout << "You will get to choose from 3 different description options"
                    "each correct anwser will return a point.\n";
                    cout << "You can also add and delete commands as needed.\n";
                    cout << "================================= Game Rule"
                    "===================================" << endl << endl;
                    break;
                }
                case 2: case 3: // 2. Play Game; 3. Load Previous Game
                {
                    cout << "Please enter your name: ";
                    cin >> userName;
                    do
                    {
                        cout << "How many questions could you like to try?(5-30)";
                        cin >> questionCount;
                    }while(questionCount > 30 || questionCount < 5);

                    break;
                }
                case 4: // Add Command
                {
                    cout << "To add a command to the library, please enter the"
                    "command name that you would add: ";
                    cin >> newCommandToAdd;
                    break;
                }
                case 5: // Remove Command
                {
                    cout << "Please enter the name of the command that you would"
                    "remove: ";
                    cin >> oldCommandTodelete;
                    break;
                }
                case 6: // Exit
                {
                    return 0;
                }
            } // end of switch(selection)
        } // end of else: check (cin.fail())
    } // end of while(true)
}

