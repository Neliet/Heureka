#include "fileReading.h"
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
		int x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;
		vertexSet.insert(Crossing{x1, y1});
	}

	std::vector<Map::VertexBaseType> vertices(vertexSet.begin(), vertexSet.end());
	using Edge = std::pair<Map::EdgeBaseType, std::vector<Map::VertexBaseType>::difference_type>;
	std::vector<std::vector<Edge>> edges(vertices.size());

	file.clear();
	file.seekg(0);

	while (file) {
		int x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;

		auto i1 = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), Crossing{x1, y1}));
		auto i2 = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), Crossing{x2, y2}));

		double distance = std::hypot(x2-x1,y2-y1);
		edges[i1].emplace_back(Road{name, distance}, i2);
	}

	file.close();
	return Map(vertices.begin(), vertices.end(), edges.begin());
}

KnowledgeBase readKnowledgeBase(const std::string& filename) {
	std::ifstream file(filename);

	if(!file) {
		throw std::runtime_error("File failed to open.");
	}

	std::unordered_set<KnowledgeBase::VertexBaseType> vertexSet;

	while (file) {
        std::unordered_set<std::string> tmp_head;
        std::unordered_set<std::string> tmp_tail;

		std::string current;
		file >> current;
		while((current != "if") && (current != "\n"))
        {
            tmp_head.insert(current);
            file >> current;
        }
        if(current == "if")
        {
            file >> current;
            while(current != "\n")
            {
                tmp_tail.insert(current);
                file >> current;
            }
        }

		vertexSet.insert(Clause{head});
		vertexSet.insert(Clause{tail});
		IfRule{Clause{head},Clause{tail}};

	}

	std::vector<KnowledgeBase::VertexBaseType> vertices(vertexSet.begin(), vertexSet.end());
	using Edge = std::pair<KnowledgeBase::EdgeBaseType, std::vector<KnowledgeBase::VertexBaseType>::difference_type>;
	std::vector<std::vector<Edge>> edges(vertices.size());

	// Deuxième lecture du fichier pour faire les edges
	file.clear();
	file.seekg(0);

	while (file) {

        std::unordered_set<std::string> tmp_head;
        std::unordered_set<std::string> tmp_tail;

		std::string curent;
		file >> curent;
		while((curent != "if") && (curent != "\n"))
        {
            tmp_head.insert(curent);
            file >> curent;
        }
        if(curent == "if")
        {
            file >> curent;
            while(curent != "\n")
            {
                tmp_tail.insert(curent);
                file >> curent;
            }
        }

	}

		auto i1 = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), Clause{head}));
		auto i2 = std::distance(vertices.begin(), std::find(vertices.begin(), vertices.end(), Clause{tail}));

		edges[i1].emplace_back(IfRule{Clause{head},Clause{tail}}, i2);
	}

	file.close();
	return KnowledgeBase(vertices.begin(), vertices.end(), edges.begin());
}
