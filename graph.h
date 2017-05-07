#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <utility>

template<typename Base, typename VertexIterator>
struct Edge : public Base {
	Edge(Base base, VertexIterator end);
	Edge& operator=(const Edge& other) = default;
	VertexIterator end;
};

template<typename VertexBase, typename EdgeBase>
struct Graph;

template<typename Base, typename EdgeBase>
struct Vertex : public Base {
	using IteratorType = typename std::vector<Vertex>::iterator;
	using EdgeType = Edge<EdgeBase, IteratorType>;
	using EdgeSetType = std::vector<EdgeType>;
	using GraphType = Graph<Base, EdgeBase>;

	Vertex(GraphType& graph, const Base& base, const std::vector<EdgeType>& edges);
	Vertex(const Vertex& other)
	: edges(other.edges), parent(other.parent), weight(other.weight),
	_successors(other._successors), graph(other.graph) {}
	Vertex& operator=(const Vertex& other) {
        edges = other.edges;
        parent = other.parent;
        weight = other.weight;
        _successors = other._successors;
        graph = other.graph;
	}

	auto successors() -> const std::vector<IteratorType>&;
	bool isStart();
	auto selfIterator() const -> IteratorType;

	EdgeSetType edges;
	IteratorType parent;
	double weight;

private:
	std::vector<IteratorType> _successors;
	GraphType& graph;
};

template<typename Base, typename EdgeBase>
bool operator>(const Vertex<Base, EdgeBase> &lhs, const Vertex<Base, EdgeBase> &rhs) {
    return lhs.weight > rhs.weight;
}

template<typename VertexBase, typename EdgeBase>
struct Graph {
	using VertexBaseType = VertexBase;
	using EdgeBaseType = EdgeBase;
	using VertexType = Vertex<VertexBase, EdgeBase>;
	using EdgeType = typename VertexType::EdgeType;
	using VertexSetType = std::vector<VertexType>;
	using EdgeSetType = typename VertexType::EdgeSetType;
	using VertexIterator = typename VertexSetType::iterator;
	using Path = std::vector<VertexIterator>;

	Graph() = default;
	template<typename VertexIt, typename EdgeIt>
	Graph(VertexIt vBegin, VertexIt vEnd, EdgeIt eBegin);

	auto operator[](const VertexBaseType& vertex) -> VertexIterator;
	void startAt(const VertexBaseType& vertex);
	bool isStart(const VertexBaseType& vertex);
	auto makePath() -> Path;

private:
	VertexSetType vertices;
	VertexIterator start;
};

#include "graph.hxx"

#endif // GRAPH_H_INCLUDED
