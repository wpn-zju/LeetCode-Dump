class Solution {
public:
	bool checkMagicSquare(vector<vector<int>>& grid, int i, int j) {
		vector<bool> count(10, false);
		for (int x = i - 1; x <= i + 1; ++x)
			for (int y = j - 1; y <= j + 1; ++y)
				if (!grid[x][y] || grid[x][y] >= 10 || count[grid[x][y]])
					return false;
                else
                    count[grid[x][y]] = true;
		return
            grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] == 15 &&
            grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] == 15 &&
            grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] == 15 &&
            grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] == 15;
	}

	int numMagicSquaresInside(vector<vector<int>>& grid) {
		int result = 0;
		for (int i = 1; i < grid.size() - 1; ++i)
			for (int j = 1; j < grid[0].size() - 1; ++j)
				if (grid[i][j] == 5)
					result += checkMagicSquare(grid, i, j);
		return result;
	}
};