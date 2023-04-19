class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		k %= (m * n);
		vector<vector<int>> result(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int t = i * n + j - k + m * n;
				t %= (m * n);
				result[i][j] = grid[t / n][t % n];
			}
		}
		return result;
	}
};