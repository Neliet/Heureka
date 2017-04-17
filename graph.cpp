#include <vector>

template<typename Vertex>
using Graph = std::vector<Vertex>;

template<typename Base, typename Edge>
class Vertex : public Base {
public:
	std::vector<Vertex> successors();
private:
	std::vector<Edge> edges;
};

typename<typename Base>
struct Edge : public Base {
	Vertex end;
};
