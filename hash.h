//reference: http://en.cppreference.com/w/cpp/utility/hash
#pragma once

#include "NodeClass.h"

namespace std
{
	bool operator== (Node const& lhs, Node const& rhs) {
		return (lhs.state == rhs.state && rhs.path == lhs.path);
	}

	template<> 
	struct hash<Node>
	{
		typedef Node argument_type;
		typedef std::size_t result_type;
		result_type operator()(argument_type const& n) const
		{
			result_type const h1(std::hash<std::string>()(n.state));
			result_type const h2(std::hash<std::string>()(n.path));
			return h1 ^ (h2 << 1); // or use boost::hash_combine
		}
	};
}