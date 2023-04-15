static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		vector<vector<int>> output = vector<vector<int>>(grid);
		vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
		int tmp = grid[r0][c0];
		dfsCB(output, grid, visited, r0, c0, tmp, color);
		return output;
	}

	void dfsCB(vector<vector<int>>& output, vector<vector<int>>& data, vector<vector<bool>>& visited, int x, int y, int& origin, int& target) {
		if (visited[x][y])
			return;
		visited[x][y] = true;
		if (x == 0 || x == data.size() - 1 || y == 0 || y == data[0].size() - 1)
			output[x][y] = target;
		else if (data[x - 1][y] == data[x + 1][y] && data[x][y - 1] == data[x][y + 1] && data[x][y] == data[x][y - 1] && data[x][y] == data[x - 1][y])
			;
		else
			output[x][y] = target;
		if (x != 0 && data[x - 1][y] == origin)
			dfsCB(output, data, visited, x - 1, y, origin, target);
		if (x != data.size() - 1 && data[x + 1][y] == origin)
			dfsCB(output, data, visited, x + 1, y, origin, target);
		if (y != 0 && data[x][y - 1] == origin)
			dfsCB(output, data, visited, x, y - 1, origin, target);
		if (y != data[0].size() - 1 && data[x][y + 1] == origin)
			dfsCB(output, data, visited, x, y + 1, origin, target);
	}
};