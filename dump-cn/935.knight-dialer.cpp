class Solution {
public:
	int knightDialer(int N) {
		if (N == 1)
			return 10;
		vector<vector<uint32_t>> dp(2, vector<uint32_t>(10, 0));
		for (int i = 0; i < 10; ++i)
			dp[0][i] = 1;
		dp[0][5] = 0;
		bool tag = true;
		for (int i = 1; i < N; ++i) {
			dp[tag][0] = (dp[!tag][4] + dp[!tag][6]) % 1000000007;
			dp[tag][1] = (dp[!tag][6] + dp[!tag][8]) % 1000000007;
			dp[tag][2] = (dp[!tag][7] + dp[!tag][9]) % 1000000007;
			dp[tag][3] = (dp[!tag][4] + dp[!tag][8]) % 1000000007;
			dp[tag][4] = (dp[!tag][3] + dp[!tag][9] + dp[!tag][0]) % 1000000007;
			dp[tag][6] = (dp[!tag][1] + dp[!tag][7] + dp[!tag][0]) % 1000000007;
			dp[tag][7] = (dp[!tag][2] + dp[!tag][6]) % 1000000007;
			dp[tag][8] = (dp[!tag][1] + dp[!tag][3]) % 1000000007;
			dp[tag][9] = (dp[!tag][4] + dp[!tag][2]) % 1000000007;
			tag = !tag;
		}
		uint64_t result = 0;
		for (uint32_t& i : dp[!tag])
			result += i;
		return result % 1000000007;
	}
};