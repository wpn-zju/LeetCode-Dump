class Solution {
public:
	int kInversePairs(int n, int k) {
		vector<vector<uint32_t>*> dp(2, new vector<uint32_t>(k + 1, 0));
		bool tag = true;
		for (int i = 1; i <= n; ++i) {
			dp[tag]->clear();
			dp[tag] = new vector<uint32_t>(k + 1, 0);
			(*dp[0])[0] = (*dp[1])[0] = 1;
			for (int t = 1; t <= k; ++t) {
				(*dp[tag])[t] = t >= i ?
					((*dp[!tag])[t] + (*dp[tag])[t - 1] - (*dp[!tag])[t - i] + 1000000007) % 1000000007 :
					((*dp[!tag])[t] + (*dp[tag])[t - 1]) % 1000000007;
			}
			tag = !tag;
		}
		return (*dp[!tag]).back();
	}
};