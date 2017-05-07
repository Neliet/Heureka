#include "knowledgeBase.h"

bool operator==(Clause lhs, Clause rhs) {
	return lhs.literals == rhs.literals;
}
