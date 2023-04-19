static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int result = 0;
		queue<pair<int, int>> myQueue;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j] == 1)
					myQueue.push({ i,j });
		if (myQueue.size() == 0 || myQueue.size() == grid.size()*grid[0].size())
			return -1;
		while (!myQueue.empty()) {
			pair<int, int> cur = myQueue.front();
			result = max(result, grid[cur.first][cur.second]);
			if (cur.first != 0 && grid[cur.first - 1][cur.second] == 0) {
				grid[cur.first - 1][cur.second] = grid[cur.first][cur.second] + 1;
				myQueue.push({ cur.first - 1, cur.second });
			}
			if (cur.first != grid.size() - 1 && grid[cur.first + 1][cur.second] == 0) {
				grid[cur.first + 1][cur.second] = grid[cur.first][cur.second] + 1;
				myQueue.push({ cur.first + 1, cur.second });
			}
			if (cur.second != 0 && grid[cur.first][cur.second - 1] == 0) {
				grid[cur.first][cur.second - 1] = grid[cur.first][cur.second] + 1;
				myQueue.push({ cur.first, cur.second - 1 });
			}
			if (cur.second != grid[0].size() - 1 && grid[cur.first][cur.second + 1] == 0) {
				grid[cur.first][cur.second + 1] = grid[cur.first][cur.second] + 1;
				myQueue.push({ cur.first, cur.second + 1 });
			}
			myQueue.pop();
		}
		return result - 1;
	}
};