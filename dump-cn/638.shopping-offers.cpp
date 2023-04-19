static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		while (price.size() < 6)
			price.push_back(0);
		while (needs.size() < 6)
			needs.push_back(0);
		for (vector<int>& vec : special) {
			while (vec.size() < 7) {
				vector<int>::iterator it = vec.end();
				vec.insert(--it, 0);
			}
		}
		vector<vector<vector<vector<vector<vector<int>>>>>> dp(needs[0] + 1,
			vector<vector<vector<vector<vector<int>>>>>(needs[1] + 1,
				vector<vector<vector<vector<int>>>>(needs[2] + 1,
					vector<vector<vector<int>>>(needs[3] + 1,
						vector<vector<int>>(needs[4] + 1,
							vector<int>(needs[5] + 1))))));
		for (int a = 0; a < dp.size(); ++a)
			for (int b = 0; b < dp[0].size(); ++b)
				for (int c = 0; c < dp[0][0].size(); ++c)
					for (int d = 0; d < dp[0][0][0].size(); ++d)
						for (int e = 0; e < dp[0][0][0][0].size(); ++e)
							for (int f = 0; f < dp[0][0][0][0][0].size(); ++f)
								dp[a][b][c][d][e][f] = a * price[0] + b * price[1] + c * price[2] + d * price[3] + e * price[4] + f * price[5];
		for (vector<int>& vec : special)
			for (int a = vec[0]; a < dp.size(); ++a)
				for (int b = vec[1]; b < dp[0].size(); ++b)
					for (int c = vec[2]; c < dp[0][0].size(); ++c)
						for (int d = vec[3]; d < dp[0][0][0].size(); ++d)
							for (int e = vec[4]; e < dp[0][0][0][0].size(); ++e)
								for (int f = vec[5]; f < dp[0][0][0][0][0].size(); ++f)
									dp[a][b][c][d][e][f] = min(dp[a][b][c][d][e][f], dp[a - vec[0]][b - vec[1]][c - vec[2]][d - vec[3]][e - vec[4]][f - vec[5]] + vec[6]);
		return dp.back().back().back().back().back().back();
	}
};