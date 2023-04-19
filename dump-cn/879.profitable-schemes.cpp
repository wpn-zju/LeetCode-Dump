class Solution {
public:
	int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
		vector<vector<int>> dp(G + 1, vector<int>(P + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < group.size(); ++i) {
			for (int j = G - group[i]; j >= 0; --j) {
				int mx = max(0, P - profit[i]);
				for (int k = P; k >= mx; --k) {
					dp[j + group[i]][P] += dp[j][k];
					dp[j + group[i]][P] %= 1000000007;
				}
				for (int k = P - profit[i] - 1; k >= 0; --k) {
					dp[j + group[i]][k + profit[i]] += dp[j][k];
					dp[j + group[i]][k + profit[i]] %= 1000000007;
				}
			}
		}
		int64_t result = 0;
		for (int i = 0; i <= G; ++i)
			result += dp[i].back();
		return result % 1000000007;
	}
};