#include <unordered_set>
#include <unordered_map>

#include <iostream>

template<typename State, typename Frontier>
bool backwardsChaining<State, Frontier>::operator()(State& initialState) {

std::cout << "a\n";
	Frontier frontier;
std::cout << "b\n";
	initialState.parent = initialState.selfIterator();
std::cout << "c\n";
	frontier.push(initialState);
std::cout << "d\n";

	std::unordered_set<State> explored;
std::cout << "e\n";
	explored.insert(initialState);
std::cout << "f\n";

	while (!frontier.empty()) {
		auto current = frontier.top();
		frontier.pop();
		if (current.isStart()) {
			return true;
		}

		for (auto& it : current.successors()) {
			if (explored.find(*it) == explored.end()) {
				it->setParent(current);
				frontier.push(*it);
				explored.insert(*it);
			}
		}
	}

	return false;
}
