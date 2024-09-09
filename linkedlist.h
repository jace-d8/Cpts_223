#pragma once
#include <fstream>
#include "Node.h"
using std::ifstream;
// Must be a singly linked list

template <typename t, typename d>
class Linked_List
{
public:
    Linked_List(){_head = NULL;}; // NULL > nullptr?
    ~Linked_List();

    bool removeFromFront();

    void insert_at_front(Node<t, d> *new_node);

    void open_file(const std::string& file_name);

    void upload_file();

    void close_file();

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
        removeFromFront();
    }
}
template<typename t, typename d>
bool Linked_List<t,d >::removeFromFront()
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
    //_input_stream.open("commands.csv", std::ios::in); weird error
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
bool Linked_List<t,d>::is_empty()
{
    if(_head == nullptr)
        return true;
    return false;
}
