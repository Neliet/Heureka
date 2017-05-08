#include "knowledgeBase.h"
#include <sstream>

Clause::Clause(const std::string& str) {
	std::istringstream s(str);
	Literal l;
	while (s >> l) {
		literals.insert(l);
	}
}

Clause::Clause(const char* s)
: Clause(std::string(s)) {
}

bool operator==(Clause lhs, Clause rhs) {
	return lhs.literals == rhs.literals;
}
