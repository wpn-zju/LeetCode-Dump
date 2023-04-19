class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
        int mx = 2;
		vector<unordered_map<int, int>> dp(A.size());
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				int d = A[i] - A[j];
				dp[i][d] = max(2, dp[j][d] + 1);
                mx = max(mx, dp[i][d]);
			}
		}
		return mx;
	}
};