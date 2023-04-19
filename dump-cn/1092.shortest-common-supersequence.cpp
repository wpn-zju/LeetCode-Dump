class Solution {
public:
	string shortestCommonSupersequence(string str1, string str2) {
		str1 = '#' + str1;
		str2 = '!' + str2;
		vector<vector<int>> path(str1.size(), vector<int>(str2.size(), 0));
		vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), 0));
		for (int i = 1; i < str1.size(); ++i)
			path[i][0] = 1;
		for (int i = 1; i < str2.size(); ++i)
			path[0][i] = 2;
		for (int i = 1; i < str1.size(); ++i) {
			for (int j = 1; j < str2.size(); ++j) {
				if (str1[i] == str2[j]) {
					path[i][j] = 3;
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					if (dp[i][j - 1] > dp[i - 1][j]) {
						path[i][j] = 2;
						dp[i][j] = dp[i][j - 1];
					}
					else {
						path[i][j] = 1;
						dp[i][j] = dp[i - 1][j];
					}
				}
			}
		}
		string result = "";
		int i = str1.size() - 1;
		int j = str2.size() - 1;
		while (path[i][j]) {
			switch (path[i][j])
			{
			case 1:
				result += str1[i];
				--i;
				break;
			case 2:
				result += str2[j];
				--j;
				break;
			case 3:
				result += str1[i];
				--i;
				--j;
				break;
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};