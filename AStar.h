//reference: http://www.redblobgames.com/pathfinding/a-star/implementation.html#cpp-astar
//reference: https://en.wikipedia.org/wiki/A*_search_algorithm
#pragma once
#include <string>
#include <queue>
#include <chrono>

#include "NodeClass.h"
#include "Heuristic_func.h"

template<typename HFunc>
class Astar {
	struct  MyComparison
	{
	public:
		HFunc Hcost;
		std::string goal;

		explicit MyComparison(std::string const& g) : goal(g), Hcost{} {}

		bool operator() (Node const& lhs, Node const& rhs) const
		{
			return Hcost(lhs.state, goal) + lhs.path.size() > Hcost(rhs.state, goal) + rhs.path.size();
		}
	};

public:
	Astar(std::string const& initial, std::string const& goal)
		: expanded{ 0 }, max_myQueue_length{ 0 }, myQueue{ MyComparison{ goal } }, final_path{}
	{
		Algorithm(initial, goal);
	}

	size_t expanded, max_myQueue_length;
	std::string final_path;
	std::priority_queue<Node, std::vector<Node>, MyComparison> myQueue;

	void Algorithm(std::string const& initial, std::string const& goal) {

		for (myQueue.push(Node{ initial, "" }); !myQueue.empty(); expanded++)
		{
			auto curr = myQueue.top();
			myQueue.pop();
			if (curr.state == goal)
			{
				final_path = curr.path;
				return;
			}
			for (auto child : curr.valid_children()) {
				myQueue.push(child);
			}
			max_myQueue_length = std::max(max_myQueue_length, myQueue.size());
		}
	}
};