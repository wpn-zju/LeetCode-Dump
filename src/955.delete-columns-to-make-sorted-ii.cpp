class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int count = 0;
		int ptr = 0;
		vector<bool> checked(A.size() - 1, false);
		while (ptr < A[0].size()) {
			bool deleted = false;
			for (int i = 0; i < A.size() - 1; ++i) {
				if (!checked[i] && A[i][ptr] > A[i + 1][ptr]) {
					deleted = true;
					break;
				}
			}
			if (!deleted) {
				for (int i = 0; i < A.size() - 1; ++i) {
					if (!checked[i] && A[i][ptr] < A[i + 1][ptr]) {
						checked[i] = true;
					}
				}
			}
			count += deleted;
			++ptr;
		}
		return count;
	}
};