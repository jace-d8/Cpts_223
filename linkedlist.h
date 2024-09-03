#pragma once
#include <fstream>
#include "Node.h"
// Must be a singly linked list
template <typename t, typename d>
class Node {
public:
    Node();
    ~Node() = default;
private:
    Node* _next;
    string _name;
    string _score;
};

template <typename t, typename d>
class Linked_List
{
public:
    Linked_List(Node<t, d> new_head): _head(){}
    ~Linked_List();
private:
    Node<t, d> * _head; // No clue why their needs to be a two type template... the command and description
    // - will always just be strings
};

template<typename t, typename d>
Linked_List<t, d>::~Linked_List() {
    delete _head;
}

