class Solution {
public:
	struct HashFuncPair {
		size_t operator()(const pair<int, int>& key) const {
			return (hash<unsigned long long>()(((unsigned long long)key.first << 32) + key.second));
		}
	};

	struct EqualKeyPair {
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}
	};
    
    unordered_map<pair<int, int>, int, HashFuncPair, EqualKeyPair> nodeMapPS;
	int pathSum(vector<int>& nums) {
		for (int& i : nums)
			nodeMapPS[pair<int, int>(i / 100, (i / 10) % 10)] = i % 10;
		int result = 0;
		dfsPS(pair<int, int>(1, 1), 0, result);
		return result;
	}

	void dfsPS(pair<int, int> pos, int sum, int& result) {
		sum += nodeMapPS[pos];
		if (!nodeMapPS.count(pair<int, int>(pos.first + 1, pos.second * 2 - 1)) && !nodeMapPS.count(pair<int, int>(pos.first + 1, pos.second * 2)))
			result += sum;
		if (nodeMapPS.count(pair<int, int>(pos.first + 1, pos.second * 2 - 1)))
			dfsPS(pair<int, int>(pos.first + 1, pos.second * 2 - 1), sum, result);
		if (nodeMapPS.count(pair<int, int>(pos.first + 1, pos.second * 2)))
			dfsPS(pair<int, int>(pos.first + 1, pos.second * 2), sum, result);
	}
};