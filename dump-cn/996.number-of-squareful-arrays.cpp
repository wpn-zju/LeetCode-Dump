class Solution {
public:
	int numSquarefulPerms(vector<int>& A) {
		unordered_map<int, int> visited;
		for (int& i : A)
			++visited[i];
		vector<int> after;
		for (pair<int, int> p : visited)
			after.push_back(p.first);
		vector<vector<int>> graph(after.size());
		for (int i = 0; i < after.size(); ++i) {
			for (int j = 0; j < after.size(); ++j) {
				int sqr = sqrt(after[i] + after[j]);
				if (sqr * sqr == after[i] + after[j]) {
					graph[i].push_back(j);
				}
			}
		}
		int result = 0;
		for (int i = 0; i < after.size(); ++i) {
			--visited[after[i]];
			bool tmp = !visited[after[i]];
			dfsFindSquare(graph, after, result, visited, after.size() - !visited[after[i]], i);
			++visited[after[i]];
		}
		return result;
	}

	void dfsFindSquare(vector<vector<int>>& graph, vector<int>& after, int& result, unordered_map<int, int>& visited, int last, int cur) {
		if (!last) {
			++result;
			return;
		}
		for (int& i : graph[cur]) {
			if (visited[after[i]]) {
				--visited[after[i]];
				dfsFindSquare(graph, after, result, visited, last - !visited[after[i]], i);
				++visited[after[i]];
			}
		}
	}
};