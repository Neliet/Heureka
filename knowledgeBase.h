#ifndef CLAUSE_H_INCLUDED
#define CLAUSE_H_INCLUDED

#include <unordered_set>
#include <string>
#include "graph.h"

using Literal = std::string;

struct Clause {
    Clause() = default;
	Clause(const std::string& s);
	std::unordered_set<Literal> literals;
};

bool operator==(Clause lhs, Clause rhs);

// Custom hash for use in unordered_set
template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

namespace std {
template<>
struct hash<Clause> {
	typedef Clause argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& clause) const {
		auto h = std::hash<Literal>{}(*clause.literals.begin());
		for (auto& it : clause.literals) {
			hash_combine<Literal>(h, it);
		}
		return h;
	}
};
}

struct IfRule {
	const std::string name;
	const double weight = 1;
};

using KnowledgeBase = Graph<Clause, IfRule>;

#endif // CLAUSE_H_INCLUDED
