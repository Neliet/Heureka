#include <algorithm>
#include <iterator>

template<typename Base, typename VertexIterator>
Edge<Base, VertexIterator>::Edge(Base base, VertexIterator end)
: Base(base), end(end) {
}

template<typename Base, typename EdgeBase>
Vertex<Base, EdgeBase>::Vertex(Base base, const std::vector<EdgeType>& edges)
: Base(base), edges(edges), isTrue(false) {
	for (auto& it : edges) {
		_successors.push_back(it.end);
	}
}

template<typename Base, typename EdgeBase>
auto Vertex<Base, EdgeBase>::successors() -> const std::vector<IteratorType>& {
	return _successors;
}

namespace std {
template<> 
template<typename Base, typename EdgeBase>
struct hash<Vertex<Base, EdgeBase>> {
	typedef Vertex<Base, EdgeBase> argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& vertex) const {
		return hash<Base>()(vertex);
	}
};
}

template<typename VertexBase, typename EdgeBase>
template<typename VertexIt, typename EdgeIt>
Graph<VertexBase, EdgeBase>::Graph(VertexIt vBegin, VertexIt vEnd, EdgeIt eBegin) {
	vertices.reserve(std::distance(vBegin, vEnd));
	for (; vBegin != vEnd; ++vBegin, ++eBegin) {
		EdgeSetType edges;
		for (auto& edge : *eBegin) {
			edges.emplace_back(edge.first, std::next(vertices.begin(), edge.second));
		}
		vertices.emplace_back(*vBegin, edges);
	}
}

template<typename VertexBase, typename EdgeBase>
auto Graph<VertexBase, EdgeBase>::operator[](const VertexBaseType& vertex) -> typename VertexSetType::iterator {
	auto it = std::find(vertices.begin(), vertices.end(), vertex);
	return it;
}
