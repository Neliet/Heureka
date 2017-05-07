#ifndef CLAUSE_H_INCLUDED
#define CLAUSE_H_INCLUDED

#include <unordered_set>

struct Literal {
	std::string name;
};

// Custom hash for use in unordered_set
namespace std {
template<>
struct hash<Literal> {
	typedef Literal argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& literal) const {
		return hash<string>{}(literal.name);
	}
};
}

struct Clause {
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
