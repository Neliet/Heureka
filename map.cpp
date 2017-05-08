#include "map.h"
#include <algorithm>

bool operator==(Crossing lhs, Crossing rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::ostream& operator<<(std::ostream& os, Map::Path&& path) {
	auto&& v = path.begin();
	for (; v+1 != path.end(); ++v) {
		os << "(" << (*v)->x << "; " << (*v)->y << ")\n";
		auto&& next = v+1;
		auto&& it = std::find_if((*next)->edges.begin(), (*next)->edges.end(),
			[&](const Map::EdgeType& edge) { return edge.end == *v; });
		if (it != (*next)->edges.end()) {
			os << it->name;
		} else {
			os << "unknown edge";
		}
		os << " -> ";
	}
	os << "(" << (*v)->x << "; " << (*v)->y << ")\n";
	return os;
}