class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int start = 1;
		int end = A.size() - 2;
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