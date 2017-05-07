#include "graph.h"
#include "map.h"
#include "fileReading.h"
#include "backwardsChaining.h"

int main()
{
    Map manhattan = readMap("data/manhattan.txt");
    //depthfirstSearch<Map::VertexType> search1;

    manhattan.startAt({0, 2});
    /*
    std::cout<< "RBFS"<<std::endl;
    search1(*manhattan[{1, 5}]);
    Map::Path path1 = manhattan.makePath();

    for (auto it = path1.begin(); it+1 != path1.end(); ++it) {
        auto next = it+1;
        auto edge = std::find_if((*next)->edges.begin(), (*next)->edges.end(),
                     [it](const Map::EdgeType& e) {
                        return e.end == (*it)->selfIterator();
                     });
        std::cout << edge->name <<std::endl;
    }
    */
    std::cout<< "A* !"<<std::endl;
    dijkstraSearch<Map::VertexType> search2;
    search2(*manhattan[{1, 5}]);
    Map::Path path2 = manhattan.makePath();
    std::cout<< "solution found"<<std::endl;
    for (auto it = path2.begin(); it+1 != path2.end(); ++it) {
        std::cout<< "iteration"<<std::endl;
        auto next = it+1;
        auto edge = std::find_if((*next)->edges.begin(), (*next)->edges.end(),
                     [it](const Map::EdgeType& e) {
                        return e.end == (*it)->selfIterator();
                     });
        std::cout << edge->name << std::endl;

    }


    return search2(*manhattan[{0, 0}]);

    /*
    Map kb = readMap("data/KB1.txt");
    depthfirstSearch<Map::VertexType> search;

    kb[{a}]->isTrue = true;

    return search(*kb[{}]);
    */
}
