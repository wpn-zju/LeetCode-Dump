class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> result(A[0].size(), vector<int>(A.size()));
		for (int i = 0; i < result.size(); ++i)
			for (int j = 0; j < result[0].size(); ++j)
				result[i][j] = A[j][i];
		return result;
	}
};