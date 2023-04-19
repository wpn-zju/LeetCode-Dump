class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= dp.size(); ++i) {
			for (string& str : wordDict) {
				if (i < str.length())
					continue;
				bool matched = true;
				for (int j = str.length() - 1, k = i - 1; j >= 0; --j, --k) {
					if (str[j] != s[k]) {
						matched = false;
						break;
					}
				}
				if (matched)
					dp[i] = dp[i] | dp[i - str.length()];
				if (dp[i])
					break;
			}
		}
		return dp.back();
	}
};