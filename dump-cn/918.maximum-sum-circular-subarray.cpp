class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		vector<int> lMax(A.size());
		vector<int> rMax(A.size());
		int cur = A[0];
		lMax[0] = A[0];
		for (int i = 1; i < A.size(); ++i) {
			cur += A[i];
			lMax[i] = max(cur, lMax[i - 1]);
		}
		cur = A[A.size() - 1];
		rMax[A.size() - 1] = A[A.size() - 1];
		for (int i = A.size() - 2; i >= 0; --i) {
			cur += A[i];
			rMax[i] = max(cur, rMax[i + 1]);
		}

		int result = INT_MIN;

		// Case 1 两端情况
		for (int i = 0; i < A.size() - 1; ++i)
			result = max(result, lMax[i] + rMax[i + 1]);

		// Case 2 普通情况
		cur = 0;
		for (int i = 0; i < A.size(); ++i) {
			if (cur < 0)
				cur = 0;
			cur += A[i];
			result = max(cur, result);
		}

		return result;
	}
};