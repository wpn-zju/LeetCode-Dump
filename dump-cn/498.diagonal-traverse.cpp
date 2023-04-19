class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return {};
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> result;
		for (int i = 0; i < m + n - 1; ++i) {
			int t1 = max(0, i - n + 1);
			int t2 = min(m - 1, i);
			if (i & 1)
				for (int j = t1; j <= t2; ++j)
					result.push_back(matrix[j][i - j]);
			else
				for (int j = t2; j >= t1; --j)
					result.push_back(matrix[j][i - j]);
		}
		return result;
	}
};