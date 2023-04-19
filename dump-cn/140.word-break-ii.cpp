class Solution {
public:
	bool wordBreakJudge(string& s, vector<string>& wordDict) {
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

	vector<string> wordBreak(string& s, vector<string>& wordDict) {
		if (!wordBreakJudge(s, wordDict))
			return vector<string>();
		vector<vector<string>> dp(s.length() + 1);
		dp[0].push_back("");
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
					for (string& str2 : dp[i - str.length()])
						if (str2.length())
							dp[i].push_back(str2 + ' ' + str);
						else
							dp[i].push_back(str);
			}
		}
		return dp.back();
	}
};