class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		vector<int> dp(s2.length() + 1, false);
		dp[0] = 1;
		for (int i = 1; i <= s2.length(); ++i)
			dp[i] = dp[i - 1] && s2[i - 1] == s3[i - 1];
		for (int i = 0; i < s1.length(); ++i) {
			dp[0] = dp[0] && s1[i] == s3[i];
			for (int j = 0; j < s2.length(); ++j)
				dp[j + 1] = dp[j + 1] && s1[i] == s3[i + j + 1] || dp[j] && s2[j] == s3[i + j + 1];
		}
		return dp.back();
	}
};