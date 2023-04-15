class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		for (int i = 1; i <= matrix.size(); ++i) {
			for (int j = 1; j <= matrix[0].size(); ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}

		int result = INT_MIN;
		for (int i = 1; i <= matrix.size(); ++i) {
			for (int j = 1; j <= matrix[0].size(); ++j) {
				for (int t = 0; t < i; ++t) {
					for (int l = 0; l < j; ++l) {
						if (dp[i][j] - dp[t][j] - dp[i][l] + dp[t][l] <= k){
                            result = max(result, dp[i][j] - dp[t][j] - dp[i][l] + dp[t][l]);
                        }
					}
				}
			}
		}

		return result;
	}
};