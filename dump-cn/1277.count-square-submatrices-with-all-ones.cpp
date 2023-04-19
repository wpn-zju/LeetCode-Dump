class Solution {
public:
	int countSquares(vector<vector<int>>& grid) {
		int result = 0;
		result += grid[0][0];
		for (int i = 1; i < grid.size(); ++i)
			result += grid[i][0];
		for (int i = 1; i < grid[0].size(); ++i)
			result += grid[0][i];
		for (int i = 1; i < grid.size(); ++i) {
			for (int j = 1; j < grid[0].size(); ++j) {
				if (grid[i][j]) {
					result += grid[i][j] = min(min(grid[i - 1][j], grid[i][j - 1]), grid[i - 1][j - 1]) + 1;
				}
			}
		}
		return result;
	}
};