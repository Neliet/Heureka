#include "road.h"
#include "graph.h"
#include "fileReading.h"
#include "crossing.h"
#include "backwardsChaining.h"

int main()
{
    Map manhattan = readMap("data/manhattan.txt");
    depthfirstSearch<Map::VertexType> search;

    manhattan.find({0, 2})->isTrue = true;

    return search(*manhattan.find({0, 0}));
}