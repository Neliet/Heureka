#ifndef CROSSING_H_INCLUDED
#define CROSSING_H_INCLUDED

#include <functional>

struct Crossing {
	const double x;
	const double y;
};

bool operator==(Crossing lhs, Crossing rhs);

// Custom hash for use in unordered_set
namespace std {
template<>
struct hash<Crossing> {
	typedef Crossing argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& crossing) const {
		return static_cast<int64_t>(crossing.x) ^ (static_cast<int64_t>(crossing.y) << 1);
	}
};
}

#endif // CROSSING_H_INCLUDED
