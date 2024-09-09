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
#include "linkedlist.h"

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

    while (true)
    {
        cout << "Please select an option listed below:\n";
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit\n";
        int selection;
        cin >> selection;

        if (selection == 2) // Play Game
        {
            // =====================
            // ===== some code =====
            // =====================
        }
        else if (selection == 1) // Game Rules
        {
            // =====================
            // ===== some code =====
            // =====================
        }
        else if (selection == 3) // Load Previous Game
        {
            // =====================
            // ===== some code =====
            // =====================
        }
        else if (selection == 4) // Add Command
        {
            // =====================
            // ===== some code =====
            // =====================
        }
        else if (selection == 5) // Remove Command
        {
            // =====================
            // ===== some code =====
            // =====================
        }
        else if (selection == 6) // Exit
        {
            // =====================
            // ===== some code =====
            // =====================
            return 0;
        }
    }
}

