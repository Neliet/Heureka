#include "road.h"
#include "graph.h"
#include "fileReading.h"
#include "crossing.h"
#include "backwardsChaining.h"

int main()
{
    Map manhattan = readMap("data/manhattan.txt");
    depthfirstSearch<Map::VertexType> search;

    manhattan.startAt({0, 2});

    search(*manhattan[{0, 0}]);
    Path path = manhattan.makePath();
    return search(*manhattan[{0, 0}]);

    /*
    Map kb = readMap("data/KB1.txt");
    depthfirstSearch<Map::VertexType> search;

    kb[{a}]->isTrue = true;

    return search(*kb[{}]);
    */
}
