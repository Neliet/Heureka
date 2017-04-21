#include "fileReading.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>

Map readMap(const std::string& filename) {
	std::ifstream file(filename);

	if(!file) {
		std::cerr << "File failed to open.\n";
		return Map();
	}

	std::unordered_set<Map::VertexBaseType> vertexSet;

	while (file) {
		int x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;
		// sscanf(line.data(), "%d %d", &x, &y);

		vertexSet.insert(Crossing{x1, y1});
	}

	std::vector<Map::VertexBaseType> vertices;
	for (auto& it : vertexSet) {
		vertices.push_back(it);
	}
	std::vector<std::vector<std::pair<Map::EdgeBaseType, std::size_t>>> edges(vertices.size());

	file.clear();
	file.seekg(0);
	/*file.close();
	file.open("heureka.txt");*/

	while (file) {
		int x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;

		// sscanf(line.data(), "%d %d %s %d %d", &x1, &y1, name.data(), &x2, &y2);

		auto it1 = std::find(vertices.begin(), vertices.end(), Crossing{x1, y1});
		auto it2 = std::find(vertices.begin(), vertices.end(), Crossing{x2, y2});

		edges[it1 - vertices.begin()].emplace_back(Road{name}, std::distance(vertices.begin(), it2));
	}

	file.close();

	Map::VertexSetType graphVertices;
	graphVertices.reserve(vertices.size());
	for (std::size_t i = 0; i < vertices.size(); ++i) {
		Map::EdgeSetType graphEdges;
		for (auto& edge : edges[i]) {
			graphEdges.emplace_back(edge.first, std::next(graphVertices.begin(), edge.second));
		}
		graphVertices.emplace_back(vertices[i], graphEdges);
	}

	return Map{graphVertices};
}
