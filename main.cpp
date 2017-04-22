#include "road.h"
#include "graph.h"
#include "fileReading.h"
#include "crossing.h"
#include "backwardsChaining.h"

int main()
{
    Map manhattan = readMap("data/manhattan.txt");
    depthfirstSearch<Map::VertexType> search;

    manhattan[{0, 2}]->isTrue = true;

    return search(*manhattan[{0, 0}]);
}