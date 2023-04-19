class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		vector<vector<int>> dp(T + 1, vector<int>(T + 1, 100000000));
		vector<vector<int>> ap;
		for (vector<int>& vec : clips) {
			vec[0] = max(vec[0], 0);
			vec[1] = min(vec[1], T);
			if (vec[0] <= vec[1])
				ap.push_back({ vec[0], vec[1] });
		}
		for (int i = 0; i < ap.size(); ++i) {
			for (int j = ap[i][0]; j <= ap[i][1]; ++j) {
				for (int k = j; k <= ap[i][1]; ++k) {
					dp[j][k] = 1;
				}
			}
		}
		for (int step = 1; step <= T; ++step) {
			for (int i = 0; i <= T - step; ++i) {
				for (int j = i; j <= i + step; ++j) {
					dp[i][i + step] = min(dp[i][i + step], dp[i][j] + dp[j][i + step]);
				}
			}
		}
		return dp[0][T] == 100000000 ? -1 : dp[0][T];
	}
};