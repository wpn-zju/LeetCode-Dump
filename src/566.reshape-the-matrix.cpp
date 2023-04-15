class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.size() * nums[0].size() != r * c)
			return nums;
		int x = 0;
		int y = 0;
		vector<vector<int>> result(r, vector<int>(c));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				result[i][j] = nums[x][y];
				if (++y == nums[0].size()) {
					y = 0;
					++x;
				}
			}
		}
		return result;
	}
};