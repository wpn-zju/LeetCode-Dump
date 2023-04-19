class Solution {
public:
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		unordered_map<int, vector<int>> reverseMap;
		unordered_map<int, int> visited;
		vector<int> visitedBus(routes.size(), INT_MAX);
		for (int i = 0; i < routes.size(); ++i) {
			for (int& t : routes[i]) {
				reverseMap[t].push_back(i);
				visited[t] = INT_MAX;
			}
		}
		queue<pair<int, int>> que;
		que.push({ S,0 });
		while (!que.empty()) {
			pair<int, int>& cur = que.front();
			if (cur.first == T)
				return cur.second;
			visited[cur.first] = min(visited[cur.first], cur.second);
			for (int& i : reverseMap[cur.first]) {
				if (cur.second + 1 < visitedBus[i]) {
					visitedBus[i] = min(visitedBus[i], cur.second + 1);
					for (int& k : routes[i]) {
						if (cur.second + 1 < visited[k]) {
							que.push({ k, cur.second + 1 });
						}
					}
				}
			}
			que.pop();
		}
		return -1;
	}
};