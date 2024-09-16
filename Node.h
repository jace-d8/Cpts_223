//
// Created by Jace Dunn on 9/16/24.
//

#ifndef NODE_H
#define NODE_H
using std::string;

template <typename t, typename d>
class Node {
public:
	Node(t new_name, d new_score);
	~Node() = default;

	void set_next(Node<t, d> *next);
	Node<t, d> *get_next() const;

	void set_command(const t &command);
	t get_command() const;

	void set_description(const d &description);
	d get_description() const;

private:
	Node* _next;
	t  _command;
	d _description;
};

template<typename t, typename d>
Node<t, d>::Node(t new_name, d new_score)
{
	_next = nullptr;
	_command = new_name;
	_description = new_score;
}
template<typename t, typename d>
Node<t, d> *Node<t,d>::get_next() const
{
	return _next;
}
template<typename t, typename d>
void Node<t,d>::set_next(Node<t, d> *next)
{
	_next = next;
}

template<typename t, typename d>
t Node<t,d>::get_command() const
{
	return _command;
}

template<typename t, typename d>
void Node<t,d>::set_command(const t &command)
{
	_command = command;
}

template<typename t, typename d>
d Node<t,d>::get_description() const
{
	return _description;
}

template<typename t, typename d>
void Node<t,d>::set_description(const d &description)
{
	_description = description;
}
#endif //NODE_H
