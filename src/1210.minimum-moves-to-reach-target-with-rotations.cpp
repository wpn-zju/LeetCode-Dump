class Solution {
public:
	struct SnakeState {
		int x;
		int y;
		bool dir;

		SnakeState(int x, int y, bool dir) {
			this->x = x;
			this->y = y;
			this->dir = dir;
		}
	};

	int minimumMoves(vector<vector<int>>& grid) {
		vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(2, false)));
		queue<SnakeState> que;
		que.push(SnakeState(0, 0, 0));
		visited[0][0][0] = true;
		int count = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				SnakeState& cur = que.front();
				if (cur.x == grid.size() - 1 && cur.y == grid[0].size() - 2 && cur.dir == 0)
					return count;
				if (cur.dir) {
					if (cur.x < grid.size() - 2 && !visited[cur.x + 1][cur.y][cur.dir] && !grid[cur.x + 2][cur.y]) {
						visited[cur.x + 1][cur.y][cur.dir] = true;
						que.push(SnakeState(cur.x + 1, cur.y, cur.dir));
					}
					if (cur.y < grid[0].size() - 1 && !visited[cur.x][cur.y + 1][cur.dir] && !grid[cur.x][cur.y + 1] && !grid[cur.x + 1][cur.y + 1]) {
						visited[cur.x][cur.y + 1][cur.dir] = true;
						que.push(SnakeState(cur.x, cur.y + 1, cur.dir));
					}
					if (cur.y < grid[0].size() - 1 && !visited[cur.x][cur.y][!cur.dir] && !grid[cur.x][cur.y + 1] && !grid[cur.x + 1][cur.y + 1]) {
						visited[cur.x][cur.y][!cur.dir] = true;
						que.push(SnakeState(cur.x, cur.y, !cur.dir));
					}
				}
				else {
					if (cur.x < grid.size() - 1 && !visited[cur.x + 1][cur.y][cur.dir] && !grid[cur.x + 1][cur.y] && !grid[cur.x + 1][cur.y + 1]) {
						visited[cur.x + 1][cur.y][cur.dir] = true;
						que.push(SnakeState(cur.x + 1, cur.y, cur.dir));
					}
					if (cur.y < grid[0].size() - 2 && !visited[cur.x][cur.y + 1][cur.dir] && !grid[cur.x][cur.y + 2]) {
						visited[cur.x][cur.y + 1][cur.dir] = true;
						que.push(SnakeState(cur.x, cur.y + 1, cur.dir));
					}
					if (cur.x < grid.size() - 1 && !visited[cur.x][cur.y][!cur.dir] && !grid[cur.x + 1][cur.y] && !grid[cur.x + 1][cur.y + 1]) {
						visited[cur.x][cur.y][!cur.dir] = true;
						que.push(SnakeState(cur.x, cur.y, !cur.dir));
					}
				}
				que.pop();
			}
			++count;
		}
		return -1;
	}
};