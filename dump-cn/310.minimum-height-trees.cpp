class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (n == 1)
			return { 0 };
		vector<unordered_set<int>> graph(n);
		for (vector<int>& vec : edges) {
			graph[vec[0]].insert(vec[1]);
			graph[vec[1]].insert(vec[0]);
		}
		queue<int> myQueue;
		for (int i = 0; i < n; ++i)
			if (graph[i].size() == 1)
				myQueue.push(i);
		int count = n;
		while (!myQueue.empty()) {
			int size = myQueue.size();
			count -= size;
			if (!count) {
				vector<int> result;
				while (!myQueue.empty()) {
					result.push_back(myQueue.front());
					myQueue.pop();
				}
				return result;
			}
			while (size--) {
				int cur = myQueue.front();
				for (int a : graph[cur]) {
					graph[a].erase(cur);
					if (graph[a].size() == 1)
						myQueue.push(a);
				}
				myQueue.pop();
			}
		}
		return {};
	}
};