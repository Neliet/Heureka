#include "crossing.h"

bool operator==(Crossing lhs, Crossing rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
