//reference: http://cforbeginners.com/linkedlists_create.html
#pragma once
#ifndef NODECLASS_H_
#define NODECLASS_H_

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
private:

	bool is_up()
	{
		return state.find('0') > 2;
	}
	bool is_right()
	{
		return (state.find('0') % 3) != 2;
	}
	bool is_down()
	{
		return state.find('0') < 6;
	}
	bool is_left()
	{
		return (state.find('0') % 3) != 0;
	}

	Node up()
	{
		Node child; 
		child.path = path;
		child.path += 'U';
		child.state = state;
		std::swap(child.state[state.find('0') - 3], child.state[state.find('0')]);
		return child;
	}

	Node right()
	{
		Node child; 
		child.path = path;
		child.path += 'R';
		child.state = state;
		std::swap(child.state[state.find('0') + 1], child.state[state.find('0')]);
		return child;
	}
	Node down()
	{
		Node child;
		child.path = path;
		child.path += 'D';
		child.state = state;
		std::swap(child.state[state.find('0') + 3], child.state[state.find('0')]);

		return child;
	}
	Node left()
	{
		Node child;
		child.path = path;
		child.path += 'L';
		child.state = state;
		std::swap(child.state[state.find('0') - 1], child.state[state.find('0')]);

		return child;
	}

	public:

	string state;
	string path;

	vector<Node> valid_children()
	{
		auto valid_children = vector<Node>{};
		if (is_up())
			valid_children.push_back(up());
		if (is_right())
			valid_children.push_back(right());
		if (is_down())
			valid_children.push_back(down());
		if (is_left())
			valid_children.push_back(left());
		return valid_children;
	}
};

#endif