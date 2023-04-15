class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); ++i)
			if (A[i][0] == 0)
				for (int j = 0; j < A[0].size(); ++j)
					A[i][j] = !A[i][j];

		vector<int> cols(A[0].size(), 0);
		for (int i = 0; i < A.size(); ++i)
			for (int j = 0; j < A[0].size(); ++j)
				if (A[i][j] == 1)
					cols[j]++;

		for (int i = 0; i < A[0].size(); ++i)
			if (cols[i] < (A.size() + 1) / 2)
				for (int j = 0; j < A.size(); ++j)
					A[j][i] = !A[j][i];

		int result = 0;
		for (int i = 0; i < A.size(); ++i) {
			int tmp = 0;
			for (int j = 0; j < A[0].size(); ++j) {
				tmp <<= 1;
				tmp += A[i][j];
			}
			result += tmp;
		}

		return result;
	}
};