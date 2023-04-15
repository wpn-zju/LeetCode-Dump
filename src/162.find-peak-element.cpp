class Solution {
public:
	int findPeakElement(vector<int>& A) {
		int start = 0;
		int end = A.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (A[mid + 1] > A[mid])
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};