#pragma once
#include <fstream>
#include "Node.h"
using std::ifstream;
// Must be a singly linked list

template <typename t, typename d>
class Linked_List
{
public:
    Linked_List(Node<t, d> new_head): _head(new_head){}
    ~Linked_List();

    void open_file(const std::string& file_name);

    void upload_file();

private:
    Node<t, d> * _head; // No clue why their needs to be a two type template... the command and description
    ifstream _input_stream;
};

template<typename t, typename d>
Linked_List<t, d>::~Linked_List()
{
    delete _head; // actually make this later
}



template<typename t, typename d>
void Linked_List<t, d>::open_file(const std::string& file_name)
{
    if(_input_stream.is_open())
    {
        cout<<"File not found"<<endl;
    }
    else
    {
        _input_stream.open(file_name);

    }
}

template<typename t, typename d>
void Linked_List<t,d>::upload_file()
{
    Node<t, d>* current = _head;
    char buffer[99] = "";
    while(_input_stream.good())
    {
        _input_stream.getline(buffer, 99, ',');
        current->set_command(buffer);
        _input_stream.getline(buffer, 99);
        current->set_data(buffer);

    }
}
