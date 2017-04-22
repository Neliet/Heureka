template<typename Base, typename EdgeBase>
Vertex<Base, EdgeBase>::Vertex(Base base, const std::vector<EdgeType>& edges)
: Base(base), edges(edges) {
	for (auto& it : edges) {
		_successors.push_back(it.end);
	}
}

template<typename Base, typename VertexIterator>
Edge<Base, VertexIterator>::Edge(Base base, VertexIterator end)
: Base(base), end(end) {
}

template<typename Base, typename EdgeBase>
auto Vertex<Base, EdgeBase>::successors() -> const std::vector<IteratorType>& {
	return _successors;
}