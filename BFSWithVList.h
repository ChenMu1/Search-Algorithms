#pragma once
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>
#include <chrono>
#include <iostream>

#include "NodeClass.h"

class BFSWithVList
{
public:
	BFSWithVList(std::string const& initial, std::string const& goal)
		:max_myQueue_length(0), visited{}, myQueue{}, final_path{}
	{
		Algorithm(initial, goal);
	}
	size_t max_myQueue_length = 0;
	std::queue <Node> myQueue;
	std::string final_path;
	std::unordered_set<std::string> visited;

	void Algorithm(std::string const& initial, std::string const& goal) {
		myQueue.push(Node{ initial, "" });
		while (!myQueue.empty())
		{
			max_myQueue_length = std::max(max_myQueue_length, myQueue.size());
			auto curr = myQueue.front();
			myQueue.pop();
			visited.insert(curr.state);
			if (curr.state == goal)
			{
				final_path = curr.path;
				return;
			}
			else {
				auto children = curr.valid_children();
				for (auto child : children)
				{
					if (visited.find(child.state) == visited.end()) {
						myQueue.push(child);
					}
					else {
						continue;
					}
				}
			}
		}
	}
};