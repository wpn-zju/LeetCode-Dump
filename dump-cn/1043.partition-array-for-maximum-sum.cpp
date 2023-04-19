class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		vector<int> dp(A.size() + 1, 0);
		dp[0] = 0;
		for (int i = 1; i <= A.size(); ++i) {
			int mx = A[i - 1];
			for (int j = i - 1; j >= max(0, i - K); --j) {
				dp[i] = max(dp[i], dp[j] + (mx = max(mx, A[j])) * (i - j));
			}
		}
		return dp.back();
	}
};