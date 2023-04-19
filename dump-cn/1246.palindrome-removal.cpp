class Solution {
public:
	int minimumMoves(vector<int>& arr) {
		vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), INT_MAX));
		for (int i = 0; i < arr.size(); ++i)
			dp[i][i] = 1;
		for (int step = 1; step < arr.size(); ++step) {
			for (int i = 0; i < arr.size() - step; ++i) {
				if (arr[i] == arr[i + step])
					dp[i][i + step] = step == 1 ? 1 : dp[i + 1][i + step - 1];
				else {
					for (int j = i; j < i + step; ++j)
						dp[i][i + step] = min(dp[i][i + step], dp[i][j] + dp[j + 1][i + step]);
				}
			}
		}
		return dp[0][arr.size() - 1];
	}
};