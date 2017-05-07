#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <utility>

template<typename Base, typename VertexIterator>
struct Edge : public Base {
	Edge(Base base, VertexIterator end);
	const VertexIterator end;
};

template<typename Base, typename EdgeBase>
struct Vertex : public Base {
	using IteratorType = typename std::vector<Vertex>::iterator;
	using EdgeType = Edge<EdgeBase, IteratorType>;
	using EdgeSetType = std::vector<EdgeType>;

	Vertex(Base base, const std::vector<EdgeType>& edges);

	auto successors() -> const std::vector<IteratorType>&;

	const EdgeSetType edges;
	bool isTrue;

	float weight;

private:
	std::vector<IteratorType> _successors;
};

template<typename VertexBase, typename EdgeBase>
struct Graph {
	using VertexBaseType = VertexBase;
	using EdgeBaseType = EdgeBase;
	using VertexType = Vertex<VertexBase, EdgeBase>;
	using EdgeType = typename VertexType::EdgeType;
	using VertexSetType = std::vector<VertexType>;
	using EdgeSetType = typename VertexType::EdgeSetType;

	Graph() = default;
	template<typename VertexIt, typename EdgeIt>
	Graph(VertexIt vBegin, VertexIt vEnd, EdgeIt eBegin);

	auto operator[](const VertexBaseType& vertex) -> typename VertexSetType::iterator;

private:
	VertexSetType vertices;
};

#include "graph.hxx"

#endif // GRAPH_H_INCLUDED
