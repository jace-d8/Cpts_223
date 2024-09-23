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
	ArrayNode<t, d>* insert(t name);
	void upload_file();
private:
	ArrayNode<t, d> _arr[100];
	fstream _profiles_stream;
};

template<typename t, typename d>
Array<t,d>::Array() // Download file upon init
{
	int i = 0;
	char buffer[100];
	if (!_profiles_stream.is_open())
	{
		_profiles_stream.open("profiles.csv", std::ios::in);
	}
	while(_profiles_stream.good())
	{
		_profiles_stream.getline(buffer, 99, ',');
		_arr[i].set_name(buffer);
		_profiles_stream.getline(buffer, 99);
		_arr[i].set_score(atof(buffer));
		++i;
	}
	_profiles_stream.close();
}

template<typename t, typename d>
ArrayNode<t,d>* Array<t, d>::insert(t name)
{
	for (auto & i : _arr)
	{
		if (i.get_name() == name) // If name already exists, insert/return
		{
			return &i;
		}
		if (i.get_name() == "") // Else insert at first blank spot
		{
			i.set_name(name);
			return &i;
		}
	}
	return nullptr;
}

template<typename t, typename d>
void Array<t, d>::upload_file() // Upload data to csv file
{
	_profiles_stream.open("profiles.csv", std::ios::out);
	if (_profiles_stream.is_open())
	{
		for (auto & i : _arr)
		{
			if (i.get_name() == "")
			{
				break; // Once we reach an empty node, break
			}
			_profiles_stream << i.get_name() << "," << i.get_score() << "\n";
			std::cout << i.get_name() << "," << i.get_score() << "\n";
		}
		_profiles_stream.close();
	}else
	{
		std::cout << "File could not be opened" << std::endl;
	}
}
