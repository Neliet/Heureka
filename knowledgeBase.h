#ifndef CLAUSE_H_INCLUDED
#define CLAUSE_H_INCLUDED

#include <unordered_set>
#include <string>

using Literal = std::string;

struct Clause {
	Clause(const std::string& s);
	const std::unordered_set<Literal> literals;
};

bool operator==(Clause lhs, Clause rhs);

// Custom hash for use in unordered_set
namespace std {
template<>
struct hash<Clause> {
	typedef Clause argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& clause) const {
		auto& begin = clause.literals.begin();
		result_type const h = std::hash<Literal>{}(*begin);
		for (++begin; begin != clause.literals.end(); ++begin) {
			h ^= std::hash<Literal>{}(*begin);
		}
		return h;
	}
};
}

struct IfRule {
	const std::string name;
};

#endif // CLAUSE_H_INCLUDED
