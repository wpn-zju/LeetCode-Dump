class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		K = min((int)flights.size() - 1, K);
		vector<vector<pair<int, int>>> graph(n);
		for (vector<int>& vec : flights)
			graph[vec[0]].push_back({ vec[1], vec[2] });
		int result = INT_MAX;
		vector<int> visited(graph.size(), 100000000);
		queue<int> que;
		queue<int> priceQue;
		que.push(src);
		priceQue.push(0);
		int length = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				int cur = que.front();
				int price = priceQue.front();
				visited[cur] = min(visited[cur], price);
				if (cur == dst)
					result = min(result, price);
				for (pair<int, int>& p : graph[cur]) {
					if (visited[p.first] > price + p.second) {
						que.push(p.first);
						priceQue.push(price + p.second);
					}
				}
				que.pop();
				priceQue.pop();
			}
			if (++length > K + 1)
				break;
		}
		return result == INT_MAX ? -1 : result;
	}
};