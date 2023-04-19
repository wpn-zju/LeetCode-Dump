class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int result = 0;
		for (int i = B.size(); i >= 0; --i) {
			int cur = 0;
			int ptrA = 0;
			int ptrB = i;
			while (ptrA < A.size() && ptrB < B.size()) {
				if (A[ptrA++] == B[ptrB++])
					result = max(result, ++cur);
				else
					cur = 0;
			}
			result = max(result, cur);
		}
		for (int i = A.size(); i >= 0; --i) {
			int cur = 0;
			int ptrA = i;
			int ptrB = 0;
			while (ptrA < A.size() && ptrB < B.size()) {
				if (A[ptrA++] == B[ptrB++])
					result = max(result, ++cur);
				else
					cur = 0;
			}
			result = max(result, cur);
		}
		return result;
	}
};