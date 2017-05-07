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

	std::unordered_set<Map::VertexBaseType> crossingSet;

	while (file) {
		double x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;
		crossingSet.insert(Crossing{x1, y1});
	}

	std::vector<Map::VertexBaseType> crossings(crossingSet.begin(), crossingSet.end());
	using Edge = std::pair<Map::EdgeBaseType, std::vector<Map::VertexBaseType>::difference_type>;
	std::vector<std::vector<Edge>> roads(crossings.size());

	file.clear();
	file.seekg(0);

	while (file) {
		double x1, x2, y1, y2;
		std::string name;
		file >> x1 >> y1 >> name >> x2 >> y2;

		auto i1 = std::distance(crossings.begin(), std::find(crossings.begin(), crossings.end(), Crossing{x1, y1}));
		auto i2 = std::distance(crossings.begin(), std::find(crossings.begin(), crossings.end(), Crossing{x2, y2}));

		double distance = std::hypot(x2-x1,y2-y1);
		roads[i1].emplace_back(Road{name, distance}, i2);
	}

	file.close();
	return Map(crossings.begin(), crossings.end(), roads.begin());
}

KnowledgeBase readKnowledgeBase(const std::string& filename) {
	std::ifstream file(filename);

	if(!file) {
		throw std::runtime_error("File failed to open.");
	}

	std::unordered_set<KnowledgeBase::VertexBaseType> clauseSet;

	while (file) {
		std::string line;
		std::getline(file, line);
		auto pos = line.find("if");

		clauseSet.insert(Clause(line.substr(0, pos)));
		if (pos != std::string::npos) {
			clauseSet.insert(Clause(line.substr(pos+2)));
		}
	}

	std::vector<KnowledgeBase::VertexBaseType> clauses(clauseSet.begin(), clauseSet.end());
	clauses.push_back(Clause()); // Add the empty clause
	using Edge = std::pair<KnowledgeBase::EdgeBaseType, std::vector<KnowledgeBase::VertexBaseType>::difference_type>;
	std::vector<std::vector<Edge>> ifRules(clauses.size());

	file.clear();
	file.seekg(0);

	while (file) {
		std::string line;
		std::getline(file, line);
		auto pos = line.find("if");

		if (pos != std::string::npos) {
			clauseSet.insert(Clause(line.substr(pos+2)));
		}

		auto i1 = std::distance(clauses.begin(), std::find(clauses.begin(), clauses.end(), Clause(line.substr(0, pos))));
		if (pos != std::string::npos) {
			auto i2 = std::distance(clauses.begin(), std::find(clauses.begin(), clauses.end(), Clause(line.substr(pos+2))));
			ifRules[i1].emplace_back(IfRule(), i2);
		} else {
			ifRules[i1].emplace_back(IfRule(), clauses.size()-1);
		}
	}

	file.close();
	return KnowledgeBase(clauses.begin(), clauses.end(), ifRules.begin());
}
