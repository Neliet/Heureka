#ifndef CROSSING_H_INCLUDED
#define CROSSING_H_INCLUDED

struct Crossing {
	const int x;
	const int y;
};

bool operator==(Crossing lhs, Crossing rhs);
bool operator==(Crossing lhs, Crossing rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

// Custom hash for use in unordered_set
namespace std {
template<> struct hash<Crossing> {
	typedef Crossing argument_type;
	typedef std::size_t result_type;
	result_type operator()(argument_type const& crossing) const {
		return crossing.x ^ (crossing.y << 1);
	}
};
}

#endif // CROSSING_H_INCLUDED
