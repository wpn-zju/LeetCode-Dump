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

	int topological(unordered_map<pair<int, int>, pair<int, vector<pair<int, int>>>, HashFuncPair, EqualKeyPair>& graph) {
		int count = 0;
		queue<pair<int, int>> myQueue;

		for (unordered_map<pair<int, int>, pair<int, vector<pair<int, int>>>, HashFuncPair, EqualKeyPair>::iterator iter = graph.begin(); iter != graph.end(); ++iter)
			if (!iter->second.first)
				myQueue.push(iter->first);
		while (!myQueue.empty()) {
			int size = myQueue.size();
			while (size--) {
				pair<int, int> cur = myQueue.front();
				for (pair<int, int> p : graph[cur].second)
					if (!--graph[p].first)
						myQueue.push(p);
				myQueue.pop();
			}
			count++;
		}

		return count;
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 1 && matrix[0].size() == 1)
			return 1;
		unordered_map<pair<int, int>, pair<int, vector<pair<int, int>>>, HashFuncPair, EqualKeyPair> graph;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				// L R U D
				// 被调用表 / 调用表
				if (j != 0 && matrix[i][j] > matrix[i][j - 1]) {
					graph[{i, j - 1}].first++;
					graph[{i, j}].second.push_back({ i,j - 1 });
				}
				if (j != matrix[0].size() - 1 && matrix[i][j] > matrix[i][j + 1]) {
					graph[{i, j + 1}].first++;
					graph[{i, j}].second.push_back({ i,j + 1 });
				}
				if (i != 0 && matrix[i][j] > matrix[i - 1][j]) {
					graph[{i - 1, j}].first++;
					graph[{i, j}].second.push_back({ i - 1,j });
				}
				if (i != matrix.size() - 1 && matrix[i][j] > matrix[i + 1][j]) {
					graph[{i + 1, j}].first++;
					graph[{i, j}].second.push_back({ i + 1,j });
				}
			}
		}
		return topological(graph);
	}
};