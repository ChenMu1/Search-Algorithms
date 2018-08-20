#pragma once
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>
#include <chrono>
#include <iostream>

#include "NodeClass.h"

class BFSWithoutVList
{
public:
	BFSWithoutVList(std::string const& initial, std::string const& goal)
		:max_myQueue_length(0),  myQueue{}, final_path{}
	{
		Algorithm(initial, goal);
	}
	size_t max_myQueue_length = 0;
	std::queue <Node> myQueue;
	std::string final_path;

	void Algorithm(std::string const& initial, std::string const& goal) {
		myQueue.push(Node{ initial, "" });
		while (!myQueue.empty())
		{
			max_myQueue_length = std::max(max_myQueue_length, myQueue.size());
			auto curr = myQueue.front();
			myQueue.pop();
			if (curr.state == goal)
			{
				final_path = curr.path;
				return;
			}
			else {
				auto children = curr.valid_children();
				for (auto child : children)
				{
					myQueue.push(child);
					continue;
				}
			}
		}
	}
};
