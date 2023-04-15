class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int ptrO = 1;
		for (int i = 0; i < A.size(); i += 2) {
			if (A[i] & 1) {
				while (A[ptrO] & 1)
					ptrO += 2;
				swap(A[i], A[ptrO]);
			}
		}
		return A;
	}
};