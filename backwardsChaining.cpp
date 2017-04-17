#include <unordered_set>
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
bool backwardsChaining(State initialState) {
	Frontier<State> frontier;
	frontier.push(initialState);

	std::unordered_set<State> explored;
	explored.insert(initialState);

	while (!frontier.empty()) {
		auto current = frontier.top();
		frontier.pop();
		if (current.empty()) {
			return true;
		}

		for (auto& it : current.successors()) {
			if (explored.find(it) == explored.end()) {
				frontier.push(it);
				explored.insert(it);
			}
		}
	}

	return false;
}

template<typename State>
using breadthfirstSearch<State> = backwardsChaining<State, std::queue>;
template<typename State>
using depthfirstSearch<State> = backwardsChaining<State, std::stack>;
template<typename State>
using dijkstraSearch<State> = backwardsChaining<State, std::priority_queue>;
