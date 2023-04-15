static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty())
			return false;
		int x = matrix.size() - 1;
		int y = 0;
		while (true) {
			if (x < 0 || x > matrix.size() - 1 || y < 0 || y > matrix[0].size() - 1)
				return false;
			if (matrix[x][y] < target)
				++y;
			else if (matrix[x][y] > target)
				--x;
            else
				return true;
		}
		return false;
	}
};