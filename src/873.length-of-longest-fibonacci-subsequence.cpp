class Solution {
public:
	int lenLongestFibSubseq(vector<int>& A) {
		int mx = 0;
		vector<unordered_map<int, int>> dp(A.size());
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (i + j < 40 || dp[j].count(A[i])) {
					int s = A[i] + A[j];
					dp[i][s] = max(2, dp[j][A[i]] + 1);
					mx = max(mx, dp[i][s]);
				}
			}
		}
		return mx > 2 ? mx : 0;
	}
};