static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j]) {
					if (i == 0 || grid[i - 1][j] == 0)
						result++;
					if (i == grid.size() - 1 || grid[i + 1][j] == 0)
						result++;
					if (j == 0 || grid[i][j - 1] == 0)
						result++;
					if (j == grid[0].size() - 1 || grid[i][j + 1] == 0)
						result++;
				}
			}
		}
		return result;
	}
};