class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); ++i) {
			int mx = 0;
			for (int j = 0; j < grid[0].size(); ++j) {
				result += grid[i][j] > 0;
				mx = max(mx, grid[i][j]);
			}
			result += mx;
		}
		for (int i = 0; i < grid[0].size(); ++i) {
			int mx = 0;
			for (int j = 0; j < grid.size(); ++j) {
				mx = max(mx, grid[j][i]);
			}
			result += mx;
		}
		return result;
	}
};