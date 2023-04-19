static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		vector<vector<int>> rows(grid.size(), vector<int>(grid[0].size(), 0));
		vector<vector<int>> cols(grid.size(), vector<int>(grid[0].size(), 0));
		for (int i = 0; i < grid.size(); ++i) {
			int cur = 0;
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j]) {
					rows[i][j] = ++cur;
				}
				else {
					rows[i][j] = cur = 0;
				}
			}
		}
		for (int i = 0; i < grid[0].size(); ++i) {
			int cur = 0;
			for (int j = 0; j < grid.size(); ++j) {
				if (grid[j][i]) {
					cols[j][i] = ++cur;
				}
				else {
					cols[j][i] = cur = 0;
				}
			}
		}
		int result = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				int t = min(i, j);
				for (int k = 1; k <= t + 1; ++k) {
					if (!grid[i - k + 1][j] || !grid[i][j - k + 1])
						break;
					if (rows[i - k + 1][j] >= k && cols[i][j - k + 1] >= k) {
						result = max(result, k * k);
					}
				}
			}
		}
		return result;
	}
};