class Solution {
public:
	int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
		int m = grid.size();
		int n = grid[0].size();
		int result = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0') {
					int count = 0;
					int ptr = i - 1;
					while (ptr >= 0 && grid[ptr][j] != 'W') {
						if (grid[ptr][j] == 'E')
							++count;
						--ptr;
					}
					ptr = i + 1;
					while (ptr < m && grid[ptr][j] != 'W') {
						if (grid[ptr][j] == 'E')
							++count;
						++ptr;
					}
					ptr = j - 1;
					while (ptr >= 0 && grid[i][ptr] != 'W') {
						if (grid[i][ptr] == 'E')
							++count;
						--ptr;
					}
					ptr = j + 1;
					while (ptr < n && grid[i][ptr] != 'W') {
						if (grid[i][ptr] == 'E')
							++count;
						++ptr;
					}
					result = max(result, count);
				}
			}
		}
		return result;
	}
};