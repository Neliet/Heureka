#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <utility>

template<typename Base, typename VertexIterator>
struct Edge : public Base {
	Edge(Base base, VertexIterator end);
	const VertexIterator end;
};

template<typename VertexBase, typename EdgeBase>
struct Graph;

template<typename Base, typename EdgeBase>
struct Vertex : public Base {
	using IteratorType = typename std::vector<Vertex>::iterator;
	using EdgeType = Edge<EdgeBase, IteratorType>;
	using EdgeSetType = std::vector<EdgeType>;
	using GraphType = Graph<Base, EdgeBase>;

	Vertex(GraphType& graph, Base base, const std::vector<EdgeType>& edges);

	auto successors() -> const std::vector<IteratorType>&;
	bool isStart();
	auto selfIterator() const -> IteratorType;
	void setParent(const Vertex& parent);
	auto edgeTo(const Vertex& successor) -> const EdgeType&;

	const EdgeSetType edges;
	IteratorType parent;
	double weight;

private:
	std::vector<IteratorType> _successors;
	GraphType& graph;
};

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
