class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		vector<vector<vector<int>>> dp(boxes.size(), vector<vector<int>>(boxes.size(), vector<int>(boxes.size(), 0)));
		return removeBoxes(boxes, dp, 0, boxes.size() - 1, 0);
	}

	int removeBoxes(vector<int>& boxes, vector<vector<vector<int>>>& dp, int i, int j, int k) {
		if (i > j)
			return 0;
		if (dp[i][j][k])
			return dp[i][j][k];
		while (i < j && boxes[j - 1] == boxes[j]) {
			--j;
			++k;
		}
		dp[i][j][k] = removeBoxes(boxes, dp, i, j - 1, 0) + (1 + k) * (1 + k);
		for (int m = i; m < j; ++m) {
			if (boxes[m] == boxes[j]) {
				dp[i][j][k] = max(dp[i][j][k], removeBoxes(boxes, dp, i, m, k + 1) + removeBoxes(boxes, dp, m + 1, j - 1, 0));
			}
		}
		return dp[i][j][k];
	}
};