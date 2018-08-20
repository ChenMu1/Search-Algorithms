#pragma once
#include <unordered_set>
#include <string>
#include <stack>
#include <algorithm>

#include "NodeClass.h"
#include "hash.h"

class PDS_NoStrictList {

public:

	PDS_NoStrictList(std::string const& initial, std::string const& goal)
		:max_depth(0), max_myS_length(0), visited{ 0 }, myS{}, final_path{}
	{
		Algorithm(initial, goal);
	}

	size_t max_depth, max_myS_length = 0;
	std::stack<Node> myS;
	std::unordered_set<Node> visited;
	std::string final_path;

	void Algorithm(std::string const& initial, std::string const& goal) {

		for (max_depth = 0; ; ++max_depth)
		{
			visited.clear();
			for (myS.push(Node{ initial, "" }), visited.insert(Node{ initial, "" }); !myS.empty(); max_myS_length = std::max(max_myS_length, myS.size()))
			{
				auto curr = myS.top();
				myS.pop();

				if (curr.state == goal)
				{
					final_path = curr.path;
					return;
				}
				if (curr.path.size() >= max_depth) {
					continue;
				}
				auto children = curr.valid_children();
				for (auto child : children)
				{
					if (child.path.length() >= 2) {
						if (
							(curr.path[curr.path.length() - 1] == 'D' && child.path[child.path.length() - 1] != 'U')
							|| (curr.path[curr.path.length() - 1] == 'L' && child.path[child.path.length() - 1] != 'R')
							|| (curr.path[curr.path.length() - 1] == 'U' && child.path[child.path.length() - 1] != 'D')
							|| (curr.path[curr.path.length() - 1] == 'R' && child.path[child.path.length() - 1] != 'L')
							)
						{
							if (visited.find(child) == visited.end())
							{
								myS.push(child);
								visited.insert(child);
							}
						}
					}
					else
					{
						visited.insert(child);
						myS.push(child);
					}
				}
			}
		}
	}
};
