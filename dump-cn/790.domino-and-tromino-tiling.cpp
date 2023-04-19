class Solution {
public:
	int numTilings(int N) {
		if (N == 1)
			return 1;
		// 0 -> i 列铺完后 i + 1 列为空
		// 1 -> i 列铺完后 i + 1 列为上有下空
		// 2 -> i 列铺完后 i + 1 列为上空下有
		vector<vector<uint32_t>> dp(3, vector<uint32_t>(2, 0));
		dp[0][0] = dp[0][1] = 1;
		dp[1][0] = dp[1][1] = 2;
		int cur = 2;
		for (int i = 2; i < N; ++i) {
			switch (cur)
			{
			case 0:
				dp[0][0] = (dp[2][0] + dp[1][0] + dp[1][1] + dp[1][1]) % 1000000007;
				dp[0][1] = (dp[2][0] + dp[2][1]) % 1000000007;
				cur = 1;
				break;
			case 1:
				dp[1][0] = (dp[0][0] + dp[2][0] + dp[2][1] + dp[2][1]) % 1000000007;
				dp[1][1] = (dp[0][0] + dp[0][1]) % 1000000007;
				cur = 2;
				break;
			case 2:
				dp[2][0] = (dp[1][0] + dp[0][0] + dp[0][1] + dp[0][1]) % 1000000007;
				dp[2][1] = (dp[1][0] + dp[1][1]) % 1000000007;
				cur = 0;
				break;
			}
		}
		switch (cur)
		{
		case 0:
			return dp[2][0];
		case 1:
			return dp[0][0];
		case 2:
			return dp[1][0];
		default:
			return dp[2][0];
		}
	}
};