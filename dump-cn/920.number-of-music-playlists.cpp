class Solution {
public:
	int numMusicPlaylists(int N, int L, int K) {
		vector<vector<int64_t>> dp(2, vector<int64_t>(N));
		bool tag = true;
		dp[0][0] = N;
		for (int i = 1; i < L; ++i) {
			for (int j = 0; j < N; ++j) {
				if (j)
					dp[tag][j] = (dp[!tag][j] * max(0, j - K + 1) + dp[!tag][j - 1] * (N - j)) % 1000000007;
				else
					dp[tag][j] = dp[!tag][j] * max(0, j - K + 1) % 1000000007;
			}
			tag = !tag;
		}
		return dp[!tag][N - 1];
	}
};