class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& M) {
		int m = M.size();
		int n = M[0].size();
		for (int i = 1 - n; i < m; ++i) {
			int a = max(0, i);
			int b = min(m - 1, i + n - 1);
			for (int j = a; j < b; ++j)
				if (M[j][j - i] != M[j + 1][j + 1 - i])
					return false;
		}
		return true;
	}
};