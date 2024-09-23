//
// Created by Jace Dunn on 9/16/24.
//
#ifndef LINKED_LIST
#define LINKED_LIST
#include <fstream>
#include <iostream>
#include "Node.h"
using std::fstream;
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

    void search_and_remove(string cmd);

    void open_file(const std::string& file_name);

    void download_file();

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
    fstream _commands_stream;
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
    if(!this->is_empty())
    {
        const Node<t, d>* tempNode = _head;
        _head = _head->get_next();
        delete tempNode;
        return true;
    }
    return false;
}

template<typename t, typename d>
void Linked_List<t, d>::insert_at_front(Node<t, d> *new_node)
{
    Node<t, d>* tmp = nullptr;
    if(this->is_empty())
    {
        _head = new_node;
    }else
    {
        tmp = _head;
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
void Linked_List<t, d>::search_and_remove(string cmd)
{
    Node<t, d>* temp = _head, *previous = nullptr;
    while(temp != nullptr)
    {
        if (temp->get_command() == cmd)
        {
            if (previous == nullptr)
            {
                _head = temp->get_next();
            }
            else
            {
                previous->set_next(temp->get_next());
            }
            delete temp;
            return;
        }
        previous = temp;
        temp = temp->get_next();
    }
}

template<typename t, typename d>
void Linked_List<t, d>::open_file(const std::string& file_name)
{
    if(_commands_stream.is_open())
    {
        cout<<"File open"<<endl;
    }else
    {
        _commands_stream.open(file_name, std::ios::in);

    }
}

template<typename t, typename d>
void Linked_List<t,d>::download_file()
{
    std::string cmnd, ds;
    while (std::getline(_commands_stream, cmnd, ','))
    {
        if (std::getline(_commands_stream, ds))
        {
            insert_at_front(new Node<t, d>(cmnd, ds));
        }
    }
}

template<typename t, typename d>
void Linked_List<t, d>::upload_file()
{
    _commands_stream.open("commands.csv", std::ios::out);
    if(_commands_stream.is_open())
    {
        Node<t, d>* tmp = _head;
        while (tmp != nullptr)
        {
            // Write command and description separated by a comma, followed by a newline
            _commands_stream << tmp->get_command() << "," << tmp->get_description() << "\n";
            tmp = tmp->get_next(); // Move to the next node
        }
        _commands_stream.close();
    }else
    {
        cout<<"File not found"<<endl;
    }

}

template<typename t, typename d>
void Linked_List<t,d>::close_file()
{
    if(_commands_stream.is_open())
    {
        _commands_stream.close();
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