#ifndef BACKWARDSCHAINING_H_INCLUDED
#define BACKWARDSCHAINING_H_INCLUDED

#include <stack>
#include <queue>

/*
	State : liste de goals en logique ou croisement en pathfinding
	Frontier : conteneur de States (pile, file, priority_queue...)
	initialState est l'arrivée
	Pour le pathfinding, State.isTrue() signifie "point de départ"
*/
template<typename State, typename Frontier>
struct backwardsChaining {
	using Path = std::vector<State>;
	auto operator()(const State& initialState) -> Path;

private:
	using PathTree = std::unordered_map<State, State>;
	auto makePath(const PathTree& pathTree, const State& start) -> Path;
};

template<typename State>
using breadthfirstSearch = backwardsChaining<State, std::queue<State>>;
template<typename State>
using depthfirstSearch = backwardsChaining<State, std::stack<State>>;
template<typename State>
using dijkstraSearch = backwardsChaining<State, std::priority_queue<State>>;

#include "backwardsChaining.hxx"

#endif
