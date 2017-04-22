#include <unordered_set>
#include "backwardsChaining.h"

template<typename State, typename Frontier>
bool backwardsChaining<State, Frontier>::operator()(State initialState) {
	Frontier frontier;
	frontier.push(initialState);

	std::unordered_set<State> explored;
	explored.insert(initialState);

	while (!frontier.empty()) {
		auto current = frontier.top();
		frontier.pop();
		if (current.isTrue) {
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
