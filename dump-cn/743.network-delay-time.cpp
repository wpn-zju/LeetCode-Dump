class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<vector<int>> search(N, vector<int>(N, 100000000));
		for (vector<int>& vec : times)
			search[vec[0] - 1][vec[1] - 1] = vec[2];
		for (int i = 0; i < N; ++i)
			search[i][i] = 0;
		auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
			return a.second > b.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
		for (int i = 0; i < N; ++i)
			if (i != K - 1 && search[K - 1][i] < 100000000)
				que.push({ i,search[K - 1][i] });
		while (!que.empty()) {
			pair<int, int> cur = que.top();
			for (int i = 0; i < N; ++i) {
				if (search[cur.first][i] + cur.second < search[K - 1][i]) {
					search[K - 1][i] = search[cur.first][i] + cur.second;
					que.push({ i,search[cur.first][i] + cur.second });
				}
			}
			que.pop();
		}
		int result = INT_MIN;
		for (int& i : search[K - 1])
			result = max(result, i);
		return result == 100000000 ? -1 : result;
	}
};