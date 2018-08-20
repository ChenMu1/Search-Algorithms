#pragma once
#include <unordered_set>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>
#include <iostream>

#include "NodeClass.h"

class PDSWithoutVList {

public:

	PDSWithoutVList(std::string const& initial, std::string const& goal)
		:max_depth(0), max_myS_length(0), myS{}, final_path{}
	{
		Algorithm(initial, goal);
	}

	size_t max_depth, max_myS_length = 0, expanded;
	std::stack<Node> myS;
	std::string final_path;

	void Algorithm(std::string const& initial, std::string const& goal) {

		for (max_depth = 0; ; ++max_depth)
		{

			for (myS.push(Node{ initial, "" }); !myS.empty(); max_myS_length = std::max(max_myS_length, myS.size()))
			{
				auto curr = myS.top();
				myS.pop();
				if (curr.state == goal) {
					final_path = curr.path;
					return;
				}
				if (curr.path.size() > max_depth)
				{
					continue;
				}
				auto children = curr.valid_children();
				for (auto child : children)
				{
					expanded++;
					if (child.path.length() >= 2) {
						if ((curr.path[curr.path.length() - 1] == 'D' && child.path[child.path.length() - 1] != 'U')
							|| (curr.path[curr.path.length() - 1] == 'L' && child.path[child.path.length() - 1] != 'R')
							|| (curr.path[curr.path.length() - 1] == 'U' && child.path[child.path.length() - 1] != 'D')
							|| (curr.path[curr.path.length() - 1] == 'R' && child.path[child.path.length() - 1] != 'L'))
						{
							myS.push(child);
						}
					}
					else
					{
						myS.push(child);
					}
				}
			}
		}
	}
};