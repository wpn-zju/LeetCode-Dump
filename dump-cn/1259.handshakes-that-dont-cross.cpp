class Solution {
public:
	int numberOfWays(int num_people) {
		vector<int64_t> dp(num_people + 1, 0);
		dp[0] = 1;
		for (int i = 2; i <= num_people; i += 2) {
			for (int j = 2; j <= i; j += 2) {
				dp[i] = (dp[i] + dp[j - 2] * dp[i - j]) % 1000000007;
			}
		}
		return dp.back();
	}
};