#include <unordered_set>
#include <unordered_map>

template<typename State, typename Frontier>
bool backwardsChaining<State, Frontier>::operator()(State& initialState) {
	Frontier frontier;
	initialState.parent = initialState.selfIterator();
	frontier.push(initialState);

	std::unordered_set<State> explored;
	explored.insert(initialState);

	while (!frontier.empty()) {
		auto current = frontier.top();
		frontier.pop();
		if (current.isStart()) {
			return true;
		}

		for (auto& it : current.successors()) {
			if (explored.find(*it) == explored.end()) {
				it.setParent(current);
				frontier.push(*it);
				explored.insert(*it);
			}
		}
	}

	return false;
}
