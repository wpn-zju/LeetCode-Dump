class Solution {
public:
		bool isBipartite(vector<vector<int>>& graph) {
			vector<vector<int>> nodeMap(100, vector<int>());
			vector<bool> flag(100, false);
			vector<bool> visited(100, false);
			for (int i = 0; i < graph.size(); ++i) {
				if (!graph[i].size())
					continue;
				for (int j : graph[i])
					nodeMap[i].push_back(j);
			}

			bool result = true;
			for (int i = 0; i < 100; ++i)
				if (!visited[i] && nodeMap[i].size()) {
					flag[i] = true;
					result &= dfsBiGraph(i, visited, nodeMap, flag);
				}

			return result;
		}

		bool dfsBiGraph(int start, vector<bool>& visited, vector<vector<int>>& dic, vector<bool>& flag) {
			visited[start] = true;
			bool result = true;
			for (int i : dic[start]) {
				if (visited[i] && flag[i]== flag[start])
					return false;
				if (!visited[i]) {
					flag[i] = !flag[start];
					result &= dfsBiGraph(i, visited, dic, flag);
				}
			}
			return result;
		}
};