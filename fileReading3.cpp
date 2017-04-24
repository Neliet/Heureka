#include "fileReading3.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <stdexcept>

Map readMap(const std::string& filename) {
	std::ifstream file(filename);

	if(!file) {
		throw std::runtime_error("File failed to open.");
	}

	std::unordered_set<Map::VertexBaseType> vertexSet;

	while (file) {
        std::unordered_set<std::string> head;
        std::unordered_set<std::string> tail;

		std::string curent;
		file >> curent;
		while((curent != "if") && (curent != "\n"))
        {
            head.insert(curent);
            file >> curent;
        }
        if(curent == "if")
        {
            file >> curent;
            while(curent != "\n")
            {
                tail.insert(curent);
                file >> curent;
            }
        }

		vertexSet.insert(Clause{head, tail});
	}

	std::vector<Map::VertexBaseType> vertices(vertexSet.begin(), vertexSet.end());
	using Edge = std::pair<Map::EdgeBaseType, std::vector<Map::VertexBaseType>::difference_type>;
	std::vector<std::vector<Edge>> edges(vertices.size());

	/*
	// Deuxième lecture du fichier pour faire les edges (PB:j'arrive pas dutout a voir en quoi concistes les edges ici)
	file.clear();
	file.seekg(0);

	while (file) {
		int x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;

		auto i1 = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), Crossing{x1, y1}));
		auto i2 = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), Crossing{x2, y2}));

		edges[i1].emplace_back(Road{name}, i2);
	}

	file.close();
	return Map(vertices.begin(), vertices.end(), edges.begin());
	*/
}
