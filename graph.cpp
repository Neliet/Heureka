#include <vector>

template<typename VertexBase, typename EdgeBase>
using Graph = std::vector<Vertex<VertexBase, EdgeBase>>;

template<typename Base, typename EdgeBase>
class Vertex : public Base {
public:
	std::vector<Vertex> successors();
private:
	std::vector<EdgeBase> edges;
};

typename<typename Base>
struct Edge : public Base {
	Vertex end;
};
