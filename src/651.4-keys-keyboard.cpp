static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxA(int N) {
		if (N < 7) return N;
		vector<int> dp(N + 1);
		for (int i = 0; i < 7; ++i)
			dp[i] = i;
		for (int i = 7; i <= N; ++i)
			dp[i] = max(3 * dp[i - 4], 4 * dp[i - 5]);
		return dp.back();
	}
};