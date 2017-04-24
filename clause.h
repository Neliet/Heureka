#ifndef CLAUSE_H_INCLUDED
#define CLAUSE_H_INCLUDED

#include <unordered_set>

struct Clause { //A1 or A2... if B1 and B2...
    const std::unordered_set<std::string> head; //Or
	const std::unordered_set<std::string> tail; //And
};

// Custom hash for use in unordered_set
namespace std {
template<>
struct hash<Clause> {
	typedef Clause argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& clause) const {
	    //J'AI ESSAYER MAIS J'AI PAS REUSSI...
		result_type const h1 (std::hash<std::unordered_set<std::string>>{}(clause.head));
        result_type const h2 (std::hash<std::unordered_set<std::string>>{}(clause.tail));
		return h1 ^ (h2 << 1);
	}
};
}



#endif // CLAUSE_H_INCLUDED
