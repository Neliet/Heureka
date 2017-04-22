#include "road.h"
#include "graph.h"
#include "fileReading.h"
#include "crossing.h"
#include "backwardsChaining.h"

int main()
{
    Map manhattan = readMap("data/manhattan.txt");
    depthfirstSearch<Map::VertexType> search;
    search(manhattan.vertices[0]);

	return 1;
}