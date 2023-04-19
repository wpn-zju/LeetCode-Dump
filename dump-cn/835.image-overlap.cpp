class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int n = A.size();
		int result = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int count1 = 0;
				int count2 = 0;
				for (int k = 0; k < n - i; ++k) {
					for (int l = 0; l < n - j; ++l) {
						count1 += A[k][l] && B[k + i][l + j];
						count2 += B[k][l] && A[k + i][l + j];
					}
				}
				result = max(result, count1);
				result = max(result, count2);
			}
		}
		return result;
	}
};