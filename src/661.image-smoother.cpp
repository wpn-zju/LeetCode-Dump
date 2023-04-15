class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& result) {
		vector<vector<int>> c(result.size(), vector<int>(result[0].size(), 1));
		vector<vector<int>> M(result.size(), vector<int>(result[0].size(), 0));
		for (int i = 0; i < M.size(); ++i) {
			for (int j = 0; j < M[0].size(); ++j) {
				M[i][j] += result[i][j];
				if (i != 0) {
					++c[i - 1][j];
					M[i - 1][j] += result[i][j];
					if (j != 0) {
						++c[i - 1][j - 1];
						M[i - 1][j - 1] += result[i][j];
					}
					if (j != M[0].size() - 1) {
						++c[i - 1][j + 1];
						M[i - 1][j + 1] += result[i][j];
					}
				}
				if (j != 0) {
					++c[i][j - 1];
					M[i][j - 1] += result[i][j];
				}
				if (i != M.size() - 1) {
					++c[i + 1][j];
					M[i + 1][j] += result[i][j];
					if (j != 0) {
						++c[i + 1][j - 1];
						M[i + 1][j - 1] += result[i][j];
					}
					if (j != M[0].size() - 1) {
						++c[i + 1][j + 1];
						M[i + 1][j + 1] += result[i][j];
					}
				}
				if (j != M[0].size() - 1) {
					++c[i][j + 1];
					M[i][j + 1] += result[i][j];
				}
			}
		}
		for (int i = 0; i < M.size(); ++i)
			for (int j = 0; j < M[0].size(); ++j)
				M[i][j] /= c[i][j];
		return M;
	}
};