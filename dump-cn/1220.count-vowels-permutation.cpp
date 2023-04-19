class Solution {
public:
	int countVowelPermutation(int n) {
		vector<vector<int>> dp(2, vector<int>(5, 1));
		bool tag = true;
		for (int i = 1; i < n; ++i) {
			dp[tag][0] = ((int64_t)dp[!tag][1] + dp[!tag][2] + dp[!tag][4]) % 1000000007;
			dp[tag][1] = ((int64_t)dp[!tag][0] + dp[!tag][2]) % 1000000007;
			dp[tag][2] = ((int64_t)dp[!tag][1] + dp[!tag][3]) % 1000000007;
			dp[tag][3] = dp[!tag][2];
			dp[tag][4] = ((int64_t)dp[!tag][2] + dp[!tag][3]) % 1000000007;
			tag = !tag;
		}
		return ((int64_t)dp[!tag][0] + dp[!tag][1] + dp[!tag][2] + dp[!tag][3] + dp[!tag][4]) % 1000000007;
	}
};