#include "map.h"
#include "knowledgeBase.h"
#include "fileReading.h"
#include "backwardsChaining.h"

int main()
{
	Map manhattan = readMap("data/manhattan.txt");
	manhattan.startAt({0, 2});

	depthfirstSearch<Map::VertexType>{}(*manhattan[{1, 5}]);
	std::cout << "Map RBFS\n" << manhattan.makePath();
	
	dijkstraSearch<Map::VertexType>{}(*manhattan[{1, 5}]);
	std::cout << "Map A*\n" << manhattan.makePath();

	// KnowledgeBase kb = readKnowledgeBase("data/KB1.txt");
	// kb.startAt("a");

	// depthfirstSearch<KnowledgeBase::VertexType>{}(*kb[""]);
	// std::cout << "KnowledgeBase DFS\n" << kb.makePath();

	std::string pause;
	std::cin >> pause;
}
