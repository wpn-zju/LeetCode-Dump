class Solution {
public:
	int fixedPoint(vector<int>& A) {
		int start = 0;
		int end = A.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (A[mid] < mid)
				start = mid + 1;
			else
				end = mid;
		}
		return A[start] == start ? start : -1;
	}
};