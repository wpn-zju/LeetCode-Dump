class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (!matrix.size())
			return 0;
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
		dp[0][0] = matrix[0][0] == '1';
		for (int i = 1; i < matrix.size(); ++i)
			dp[i][0] = matrix[i][0] == '1';
		for (int i = 1; i < matrix[0].size(); ++i)
			dp[0][i] = matrix[0][i] == '1';
		for (int i = 1; i < matrix.size(); ++i)
			for (int j = 1; j < matrix[0].size(); ++j)
				if (matrix[i][j] == '1')
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				else
					dp[i][j] = 0;

		int result = 0;
		for (vector<int>& vec : dp)
			for (int& i : vec)
				result = max(result, i);
		return result * result;
	}
};