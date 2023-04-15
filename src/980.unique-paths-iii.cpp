class Solution {
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		pair<int, int> start;
		int count = 0;
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] != -1)
					count++;
				if (grid[i][j] == 1)
					start = { i,j };
			}
		int result = 0;
		int tmp = 0;
		vector<bool> mySet(grid.size()*grid[0].size(), false);
		dfsUniquePath(result, grid, mySet, start.first, start.second, count, tmp);
		return result;
	}

	void dfsUniquePath(int& result, vector<vector<int>>& grid, vector<bool>& dic, int x, int y, int& t, int& count) {
		if (grid[x][y] == -1)
			return;
		else if (grid[x][y] == 2) {
			if (count == t - 1)
				result++;
			return;
		}
		else {
			dic[x*grid[0].size() + y] = true;
			count++;
			if (x != 0 && !dic[(x - 1)*grid[0].size() + y])
				dfsUniquePath(result, grid, dic, x - 1, y, t, count);
			if (x != grid.size() - 1 && !dic[(x + 1)*grid[0].size() + y])
				dfsUniquePath(result, grid, dic, x + 1, y, t, count);
			if (y != 0 && !dic[x*grid[0].size() + y - 1])
				dfsUniquePath(result, grid, dic, x, y - 1, t, count);
			if (y != grid[0].size() - 1 && !dic[x*grid[0].size() + y + 1])
				dfsUniquePath(result, grid, dic, x, y + 1, t, count);
			dic[x*grid[0].size() + y] = false;
			count--;
		}
	}
};