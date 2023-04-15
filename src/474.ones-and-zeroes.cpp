class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		vector<pair<int, int>> data(strs.size(), { 0,0 });
		for (int i = 0; i < strs.size(); ++i)
			for (char&c : strs[i])
				if (c == '0')
					++data[i].first;
				else
					++data[i].second;
		for (pair<int, int>& p : data)
			for (int i = dp.size() - 1; i >= p.first; --i)
				for (int j = dp[0].size() - 1; j >= p.second; --j)
					dp[i][j] = max(dp[i][j], dp[i - p.first][j - p.second] + 1);
		return dp.back().back();
	}
};