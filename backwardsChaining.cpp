#include <unordered_set>

template<typename State, template<typename> class Frontier>
bool backwardsChaining(State initialState) {
	Frontier<State> frontier;
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
