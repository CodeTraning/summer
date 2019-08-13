#include <iostream>
#include <unordered_map>
using namespace std;

class SolutionOfOneTwoStep {
private:
	static unordered_map<size_t, size_t> result_;

public:
	enum class POLICY {
		RECURSIVE,
		NONRECURSIVE
	};

private:
	size_t recursive(size_t steps) {
		auto iter = result_.find(steps);
		if (result_.end() != iter) {
			return iter->second;
		} else {
			size_t res = operator()(steps - 1) + operator()(steps - 2);
			result_.insert({steps, res});
			return res;
		}
	}
	size_t nonrecursive(size_t steps) {
		auto iter = result_.find(steps);
		if (result_.end() != iter) {
			return iter->second;
		} else {
			size_t start;
			for (start = steps; start != 2 and result_.end() == result_.find(start); --start) {}
			for (size_t i = start; i != steps; ++i) {
				result_.insert({i + 1, result_[i - 1] + result_[i]});
			}
			return result_[steps];
		}
	}

public:
	size_t operator()(size_t steps, const POLICY policy = POLICY::RECURSIVE) {
		if (policy == POLICY::RECURSIVE) {
			return recursive(steps);
		} else if (policy == POLICY::NONRECURSIVE) {
			return nonrecursive(steps);
		}
	}
	static void debug() {
		for (auto kv : result_) {
			cout << kv.first << ' ' << kv.second << endl; 
		}
		cout << endl;
	}
};

// 递归终止条件
unordered_map<size_t, size_t> SolutionOfOneTwoStep::result_ = {{1, 1}, {2, 2}};

int main() {
	SolutionOfOneTwoStep::debug();

	cout << SolutionOfOneTwoStep()(5, SolutionOfOneTwoStep::POLICY::RECURSIVE) << endl;
	SolutionOfOneTwoStep::debug();

	cout << SolutionOfOneTwoStep()(10, SolutionOfOneTwoStep::POLICY::NONRECURSIVE) << endl;
	SolutionOfOneTwoStep::debug();

	cout << SolutionOfOneTwoStep()(20, SolutionOfOneTwoStep::POLICY::RECURSIVE) << endl;
	SolutionOfOneTwoStep::debug();

	return 0;
}