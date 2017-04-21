#include <stack>
#include <queue>
#include <priority_queue>

/*
	State : liste de goals en logique ou croisement en pathfinding
	Frontier : conteneur de States (pile, file, priority_queue...)
	initialState est l'arrivée
	Pour le pathfinding, State.empty() signifie "point de départ"
*/
template<typename State, typename Frontier>
bool backwardsChaining(State initialState);

template<typename State>
using breadthfirstSearch<State> = backwardsChaining<State, std::queue>;
template<typename State>
using depthfirstSearch<State> = backwardsChaining<State, std::stack>;
template<typename State>
using dijkstraSearch<State> = backwardsChaining<State, std::priority_queue>;
