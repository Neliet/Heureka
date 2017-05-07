#include <unordered_set>
#include <unordered_map>

template<typename State, typename Frontier>
auto backwardsChaining<State, Frontier>::makePath(const PathTree& pathTree, const State& start) -> Path {
	Path path{start};
	auto next = pathTree[start];
	while (next != path.back()) {
		path.push_back(next);
		next = pathTree[next];
	}
	return path;
}

template<typename State, typename Frontier>
auto backwardsChaining<State, Frontier>::operator()(const State& initialState) -> Path {
	Frontier frontier;
	frontier.push(initialState);
	PathTree pathTree{{initialState, initialState}};

	std::unordered_set<State> explored;
	explored.insert(initialState);

	while (!frontier.empty()) {
		auto current = frontier.top();
		frontier.pop();
		if (current.isTrue) {
			return makePath(pathTree, current);
		}

		for (auto& it : current.successors()) {
			if (explored.find(*it) == explored.end()) {
				frontier.push(*it);
				pathTree.emplace(*it, current);
				explored.insert(*it);
			}
		}
	}

	return {};
}
