#include "map.h"

bool operator==(Crossing lhs, Crossing rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::ostream& operator<<(std::ostream& os, const Map::Path& path) {
	for (auto current = path.begin(), next = current+1; next != path.end(); ++current, ++next) {
		os << "(" << (*current)->x << "; " << (*current)->y << ")\n";
		for (auto& edge : (*next)->edges) {
			if (edge.end == *current) {
				os << edge.name << " -> ";
			}
		}
		os << "unknown edge -> ";
	}
	return os;
}