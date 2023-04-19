class Solution {
public:
	int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int count1 = 0;
		int count2 = 0;
		int ptrL = 0;
		int ptrR = 0;
		for (int i = 0; i <= A.size(); ++i) {
			if (i == A.size() || A[i] > R) {
				int t = i - ptrR + 1;
				count1 += t * t - t >> 1;
				ptrR = i + 1;
			}
			if (i == A.size() || A[i] >= L) {
				int t = i - ptrL + 1;
				count2 += t * t - t >> 1;
				ptrL = i + 1;
			}
		}
		return count1 - count2;
	}
};