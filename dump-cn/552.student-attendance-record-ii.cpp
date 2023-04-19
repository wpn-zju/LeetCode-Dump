static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
 	int checkRecord(int n) {
		// O -> P end | 1 -> L end | 2 - A end
		vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(3, 0)));
		dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = 1;
		bool tag = true;
		for (int i = 1; i < n; ++i) {
			dp[tag][0][0] = ((int64_t)dp[!tag][0][0] + dp[!tag][0][1] + dp[!tag][0][2]) % 1000000007;
			dp[tag][0][1] = dp[!tag][0][0];
			dp[tag][0][2] = dp[!tag][0][1];
			dp[tag][1][0] = ((int64_t)dp[!tag][0][0] + dp[!tag][0][1] + dp[!tag][0][2] + dp[!tag][1][0] + dp[!tag][1][1] + dp[!tag][1][2]) % 1000000007;
			dp[tag][1][1] = dp[!tag][1][0];
			dp[tag][1][2] = dp[!tag][1][1];
			tag = !tag;
		}
		return ((int64_t)dp[!tag][0][0] + dp[!tag][0][1] + dp[!tag][0][2] + dp[!tag][1][0] + dp[!tag][1][1] + dp[!tag][1][2]) % 1000000007;
	}
};