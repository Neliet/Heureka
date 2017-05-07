#include <algorithm>
#include <iterator>
#include <stdexcept>

template<typename Base, typename VertexIterator>
Edge<Base, VertexIterator>::Edge(Base base, VertexIterator end)
: Base(base), end(end) {
}

template<typename Base, typename EdgeBase>
Vertex<Base, EdgeBase>::Vertex(GraphType& graph, const Base& base, const std::vector<EdgeType>& edges)
: Base(base), edges(edges), graph(graph) {
	for (auto& it : edges) {
		_successors.push_back(it.end);
	}
}

template<typename Base, typename EdgeBase>
auto Vertex<Base, EdgeBase>::successors() -> const std::vector<IteratorType>& {
	return _successors;
}

template<typename Base, typename EdgeBase>
bool Vertex<Base, EdgeBase>::isStart() {
    return graph.isStart(*this);
}

template<typename Base, typename EdgeBase>
auto Vertex<Base, EdgeBase>::selfIterator() -> IteratorType {
	return graph[*this];
}

template<typename Base, typename EdgeBase>
void Vertex<Base, EdgeBase>::setParent(Vertex v) {
	parent = v.selfIterator();
	weight = v.weight + v.edgeTo(selfIterator()).weight;
}

template<typename Base, typename EdgeBase>
auto Vertex<Base, EdgeBase>::edgeTo(const IteratorType& successor) -> const EdgeType& {
	for (auto& it : edges) {
		if (it.end == successor) {
			return it;
		}
	}

	throw std::runtime_error("[Vertex::edgeTo] not a successor");
}

namespace std {
template<>
template<typename Base, typename EdgeBase>
struct hash<Vertex<Base, EdgeBase>> {
	typedef Vertex<Base, EdgeBase> argument_type;
	typedef size_t result_type;
	result_type operator()(argument_type const& vertex) const {
		return hash<Base>{}(vertex);
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
		vertices.emplace_back(*this, *vBegin, edges);
	}
}

template<typename VertexBase, typename EdgeBase>
auto Graph<VertexBase, EdgeBase>::operator[](const VertexBaseType& vertex) -> typename VertexSetType::iterator {
	auto it = std::find(vertices.begin(), vertices.end(), vertex);
	return it;
}

template<typename VertexBase, typename EdgeBase>
void Graph<VertexBase, EdgeBase>::startAt(const VertexBaseType& vertex) {
	start = std::find(vertices.begin(), vertices.end(), vertex);
}

template<typename VertexBase, typename EdgeBase>
bool Graph<VertexBase, EdgeBase>::isStart(const VertexBaseType& vertex) {
    return start == std::find(vertices.begin(), vertices.end(), vertex);
}

template<typename VertexBase, typename EdgeBase>
auto Graph<VertexBase, EdgeBase>::makePath() -> Path {
	Path path{start};
	auto next = start->parent;
	while (next != path.back()) {
		path.push_back(next);
		next = path.back()->parent;
	}
	return path;
}
