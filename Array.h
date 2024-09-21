#pragma once
#include <fstream>
#include <iostream>
using std::fstream;

template<typename t, typename d>
class ArrayNode
{
	t name;
	d score;
public:
	t get_name() const;
	void set_name(const t &name);
	d get_score() const;
	void set_score(const d &score);
};

template<typename t, typename d>
t ArrayNode<t, d>::get_name() const
{
	return name;
}

template<typename t, typename d>
void ArrayNode<t, d>::set_name(const t &name)
{
	this->name = name;
}

template<typename t, typename d>
d ArrayNode<t, d>::get_score() const
{
	return score;
}

template<typename t, typename d>
void ArrayNode<t, d>::set_score(const d &score)
{
	this->score = score;
}

template<typename t, typename d>
class Array
{
public:
	Array();
	ArrayNode<t, d> insert(t name);
	ArrayNode<t, d> arr[100];
	fstream profiles;
};

template<typename t, typename d>
Array<t,d>::Array()
{
	int i = 0;
	char buffer[100];
	if (!profiles.is_open())
	{
		profiles.open("profiles.csv");
	}
	while(profiles.good())
	{
		profiles.getline(buffer, 99, ',');
		arr[i].set_name(buffer);
		profiles.getline(buffer, 99);
		arr[i].set_score(atof(buffer));
		++i;
	}
	std::cout << arr[0].get_name() << " " << arr[0].get_score();
}

template<typename t, typename d>
ArrayNode<t,d> Array<t, d>::insert(t name)
{
	for (int i = 0; i < 100; ++i)
	{
		if (arr[i].get_name() == name)
		{
			return arr[i];
		}
		if (arr[i].get_name() == "")
		{
			arr[i].set_name(name);
			return arr[i];
		}
	}
}
