static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		vector<int> rows;
		vector<int> cols;
		for (int row = 0; row < grid.size(); ++row)
			for (int col = 0; col < grid[0].size(); ++col)
				if (grid[row][col])
					rows.push_back(row);
		for (int col = 0; col < grid[0].size(); ++col)
			for (int row = 0; row < grid.size(); ++row)
				if (grid[row][col])
					cols.push_back(col);
		int col = cols[cols.size() / 2];
		int row = rows[rows.size() / 2];
		return minDistance1D(rows, row) + minDistance1D(cols, col);
	}

	int minDistance1D(vector<int>& vec, int index) {
		int result = 0;
		for (int& i : vec)
			result += abs(i - index);
		return result;
	}
};