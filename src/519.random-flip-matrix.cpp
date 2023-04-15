static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int total;
	int count;
	int n_cols;
	unordered_map<int, int> blackMap;
	Solution(int n_rows, int n_cols) {
		this->n_cols = n_cols;
		total = count = n_rows * n_cols;
	}

	vector<int> flip() {
		int r = rand() % count;
		while (blackMap.count(r))
			r = blackMap[r];
		blackMap[r] = --count;
		return { r / n_cols, r % n_cols };
	}

	void reset() {
		count = total;
		blackMap.clear();
	}
};