class Solution {
public:
	bool canCross(vector<int>& stones) {
		vector<vector<bool>> dp(stones.size(), vector<bool>(1300, false));
		dp[0][1] = true;
		for (int i = 1; i < stones.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				int d = stones[i] - stones[j];
				if (d < 1200 && dp[j][d])
					dp[i][d - 1] = dp[i][d] = dp[i][d + 1] = true;
			}
		}
		for (bool b : dp.back())
			if (b)
				return true;
		return false;
	}
};