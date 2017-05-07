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

    search(*manhattan[{1, 5}]);
    Map::Path path = manhattan.makePath();

    for (auto it = path.begin(); it+1 != path.end(); ++it) {
        auto next = it+1;
        auto edge = std::find_if((*next)->edges.begin(), (*next)->edges.end(),
                     [it](const Map::EdgeType& e) {
                        return e.end == (*it)->selfIterator();
                     });
        std::cout << edge->name;
    }

    return search(*manhattan[{0, 0}]);

    /*
    Map kb = readMap("data/KB1.txt");
    depthfirstSearch<Map::VertexType> search;

    kb[{a}]->isTrue = true;

    return search(*kb[{}]);
    */
}
