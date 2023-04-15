class Solution {
public:
	int getMaximumGold(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j]) {
					int tmp = grid[i][j];
					result = max(result, tmp);
					grid[i][j] = 0;
					dfsFindGold(grid, result, tmp, i, j);
					grid[i][j] = tmp;
				}
		return result;
	}

	void dfsFindGold(vector<vector<int>>& grid, int& result, int cur, int x, int y) {
		if (x != 0 && grid[x - 1][y]) {
			int tmp = grid[x - 1][y];
			result = max(result, cur + tmp);
			grid[x - 1][y] = 0;
			dfsFindGold(grid, result, cur + tmp, x - 1, y);
			grid[x - 1][y] = tmp;
		}
		if (x != grid.size() - 1 && grid[x + 1][y]) {
			int tmp = grid[x + 1][y];
			result = max(result, cur + tmp);
			grid[x + 1][y] = 0;
			dfsFindGold(grid, result, cur + tmp, x + 1, y);
			grid[x + 1][y] = tmp;
		}
		if (y != 0 && grid[x][y - 1]) {
			int tmp = grid[x][y - 1];
			result = max(result, cur + tmp);
			grid[x][y - 1] = 0;
			dfsFindGold(grid, result, cur + tmp, x, y - 1);
			grid[x][y - 1] = tmp;
		}
		if (y != grid[0].size() - 1 && grid[x][y + 1]) {
			int tmp = grid[x][y + 1];
			result = max(result, cur + tmp);
			grid[x][y + 1] = 0;
			dfsFindGold(grid, result, cur + tmp, x, y + 1);
			grid[x][y + 1] = tmp;
		}
	}
};