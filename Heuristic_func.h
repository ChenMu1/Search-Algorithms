//reference: https://www.cs.umd.edu/class/fall2003/cmsc421-0101/heuristic-search.pdf
#pragma once
#include <string>

class MisplacedTiles {
public:
	size_t operator()(std::string const& curr, std::string const& goal) const {
		size_t count = 0;
		for (int i = 0; i < goal.size(); i++) 
			if (curr[i] != goal[i]) count++;
		return count;
	}
};

class ManhattanDistance {
public:
	size_t operator()(std::string const& curr, std::string const& goal) const {
		size_t Hcost = 0;
		for (int i = 0; i != goal.size(); i++) {
			if (curr[i] == '0') continue;
			auto digit = curr[i] - '0';
			Hcost += abs(i / 3 - digit / 3) + abs(i % 3 - digit % 3);
		}
		return Hcost;
	}
};

