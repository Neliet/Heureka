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
	std::vector<IteratorType> successors();
	const EdgeSetType edges;
};

template<typename VertexBase, typename EdgeBase>
struct Graph {
	using VertexBaseType = VertexBase;
	using EdgeBaseType = EdgeBase;
	using VertexType = Vertex<VertexBase, EdgeBase>;
	using EdgeType = typename VertexType::EdgeType;
	using VertexSetType = std::vector<VertexType>;
	using EdgeSetType = typename VertexType::EdgeSetType;

	const VertexSetType vertices;
};


template<typename Base, typename EdgeBase>
Vertex<Base, EdgeBase>::Vertex(Base base, const std::vector<EdgeType>& edges)
: Base(base), edges(edges) {
}

template<typename Base, typename VertexIterator>
Edge<Base, VertexIterator>::Edge(Base base, VertexIterator end)
: Base(base), end(end) {
}

#endif // GRAPH_H_INCLUDED