static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int numDistinctIslands(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		set<vector<pair<int, int>>> uniMap;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					vector<pair<int, int>> tmp;
					int offsetX = i;
					int offsetY = j;
					dfsUni2(grid, offsetX, offsetY, 0, 0, tmp);
					uniMap.insert(tmp);
				}
			}
		}
		return uniMap.size();
	}

	void dfsUni2(vector<vector<int>>& grid, int& offsetX, int& offsetY, int x, int y, vector<pair<int, int>>& result) {
		int x1 = offsetX + x;
		int y1 = offsetY + y;
		if (grid[x1][y1] == 2)
			return;
		grid[x1][y1] = 2;
		result.push_back({ x,y });
		if (x1 != 0 && grid[x1 - 1][y1] == 1)
			dfsUni2(grid, offsetX, offsetY, x - 1, y, result);
		if (x1 != grid.size() - 1 && grid[x1 + 1][y1] == 1)
			dfsUni2(grid, offsetX, offsetY, x + 1, y, result);
		if (y1 != 0 && grid[x1][y1 - 1] == 1)
			dfsUni2(grid, offsetX, offsetY, x, y - 1, result);
		if (y1 != grid[0].size() - 1 && grid[x1][y1 + 1] == 1)
			dfsUni2(grid, offsetX, offsetY, x, y + 1, result);
	}
};