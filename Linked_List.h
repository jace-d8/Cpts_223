//
// Created by Jace Dunn on 9/16/24.
//
#ifndef LINKED_LIST
#define LINKED_LIST
#include <fstream>
#include <iostream>
#include "Node.h"
using std::ifstream;
using std::endl;
using std::cout;
// Must be a singly linked list

template <typename t, typename d>
class Linked_List
{
public:
    Linked_List(){_head = NULL;}; // NULL > nullptr?
    ~Linked_List();

    bool remove_from_front();

    void insert_at_front(Node<t, d> *new_node);

    bool search_linked_list(string cmd);

    void open_file(const std::string& file_name);

    void upload_file();

    Node<t, d> * get_head() const
    {
        return _head;
    }

    void close_file();

    void print_list();

    bool is_empty();

private:
    Node<t, d> * _head; // No clue why their needs to be a two type template... the command and description
    ifstream _input_stream;
};

template<typename t, typename d>
Linked_List<t, d>::~Linked_List()
{
    while(!is_empty())
    {
        remove_from_front();
    }
}
template<typename t, typename d>
bool Linked_List<t,d >::remove_from_front()
{
    const Node<t, d>* tempNode = _head;
    if(!this->is_empty())
    {
        _head = _head->get_next();
        delete tempNode;
        return true;
    }
    return false;
}

template<typename t, typename d>
void Linked_List<t, d>::insert_at_front(Node<t, d> *new_node)
{
    Node<t, d>* tmp = _head;
    if(this->is_empty())
    {
        _head = new_node;
    }else
    {
        _head = new_node;
        _head->set_next(tmp);
    }
}

template<typename t, typename d>
bool Linked_List<t, d>::search_linked_list(string cmd)
{
    Node<t, d>* temp = _head;
    while(temp != nullptr)
    {
        if (temp->get_command() == cmd)
        {
            return true;
        }
        temp = temp->get_next();
    }
    return false;
}

template<typename t, typename d>
void Linked_List<t, d>::open_file(const std::string& file_name)
{
    if(_input_stream.is_open())
    {
        cout<<"File not found"<<endl;
    }else
    {
        _input_stream.open(file_name, std::ios::in);

    }
}

template<typename t, typename d>
void Linked_List<t,d>::upload_file()
{
    char cmnd[99] = "", ds[99] = "";
    while(_input_stream.good())
    {
        _input_stream.getline(cmnd, 99, ',');
        _input_stream.getline(ds, 99);
        insert_at_front(new Node<t, d>(cmnd, ds));
    }
}

template<typename t, typename d>
void Linked_List<t,d>::close_file()
{
    if(_input_stream.is_open())
    {
        _input_stream.close();
    }
}

template<typename t, typename d>
void Linked_List<t,d>::print_list()
{
    Node<t,d>* temp = _head;
    while (temp != nullptr) {
        cout << temp->get_command() << " " << temp->get_description() << endl;
        temp = temp->get_next();
    }
    cout << endl;
}

template<typename t, typename d>
bool Linked_List<t,d>::is_empty()
{
    if(_head == nullptr)
        return true;
    return false;
}
#endif