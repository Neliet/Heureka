#include <stack>
#include <queue>

/*
	State : liste de goals en logique ou croisement en pathfinding
	Frontier : conteneur de States (pile, file, priority_queue...)
	initialState est l'arrivée
	Pour le pathfinding, State.empty() signifie "point de départ"
*/
template<typename State, typename Frontier>
struct backwardsChaining {
	bool operator()(State initialState);
};

template<typename State>
using breadthfirstSearch = backwardsChaining<State, std::queue<State>>;
template<typename State>
using depthfirstSearch = backwardsChaining<State, std::stack<State>>;
template<typename State>
using dijkstraSearch = backwardsChaining<State, std::priority_queue<State>>;
