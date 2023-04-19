class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if (grid[0][0] || grid.back().back())
			return -1;
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		queue<pair<int, int>> que;
		que.push({ 0,0 });
		visited[0][0] = true;
		int count = 1;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				pair<int, int>& cur = que.front();
				if (cur.first == grid.size() - 1 && cur.second == grid[0].size() - 1)
					return count;
				if (cur.first != 0 && !visited[cur.first - 1][cur.second] && grid[cur.first - 1][cur.second] == 0) {
					visited[cur.first - 1][cur.second] = true;
					que.push({ cur.first - 1,cur.second });
				}
				if (cur.first != grid.size() - 1 && !visited[cur.first + 1][cur.second] && grid[cur.first + 1][cur.second] == 0) {
					visited[cur.first + 1][cur.second] = true;
					que.push({ cur.first + 1,cur.second });
				}
				if (cur.second != 0 && !visited[cur.first][cur.second - 1] && grid[cur.first][cur.second - 1] == 0) {
					visited[cur.first][cur.second - 1] = true;
					que.push({ cur.first,cur.second - 1 });
				}
				if (cur.second != grid[0].size() - 1 && !visited[cur.first][cur.second + 1] && grid[cur.first][cur.second + 1] == 0) {
					visited[cur.first][cur.second + 1] = true;
					que.push({ cur.first,cur.second + 1 });
				}
				if (cur.first != 0 && cur.second != 0 && !visited[cur.first - 1][cur.second - 1] && grid[cur.first - 1][cur.second - 1] == 0) {
					visited[cur.first - 1][cur.second - 1] = true;
					que.push({ cur.first - 1,cur.second - 1 });
				}
				if (cur.first != 0 && cur.second != grid[0].size() - 1 && !visited[cur.first - 1][cur.second + 1] && grid[cur.first - 1][cur.second + 1] == 0) {
					visited[cur.first - 1][cur.second + 1] = true;
					que.push({ cur.first - 1,cur.second + 1 });
				}
				if (cur.first != grid.size() - 1 && cur.second != 0 && !visited[cur.first + 1][cur.second - 1] && grid[cur.first + 1][cur.second - 1] == 0) {
					visited[cur.first + 1][cur.second - 1] = true;
					que.push({ cur.first + 1,cur.second - 1 });
				}
				if (cur.first != grid.size() - 1 && cur.second != grid[0].size() - 1 && !visited[cur.first + 1][cur.second + 1] && grid[cur.first + 1][cur.second + 1] == 0) {
					visited[cur.first + 1][cur.second + 1] = true;
					que.push({ cur.first + 1,cur.second + 1 });
				}
				que.pop();
			}
			++count;
		}
		return -1;
	}
};