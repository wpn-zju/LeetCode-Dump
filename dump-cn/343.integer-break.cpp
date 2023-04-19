static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int integerBreak(int n) {
		vector<int> dp(n - 1);
		vector<int> sum(4);
		for (int i = 2; i <= n; ++i)
			dp[i - 2] = i - 1;
		for (int i = 4; i <= n; ++i) {
			for (int j = 2; j <= i / 2; ++j) {
				int i1 = dp[j - 2];
				int i2 = dp[i - j - 2];
				sum[0] = i1 * i2;
				sum[1] = j * (i - j);
				sum[2] = i1 * (i - j);
				sum[3] = j * i2;
				for (int& k : sum)
					dp[i - 2] = max(dp[i - 2], k);
			}
		}
		return dp.back();
	}};