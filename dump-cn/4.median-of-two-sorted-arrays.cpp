class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);
		int N = nums1.size();
		int M = nums2.size();
		int half = (N + M) / 2;
		int start = 0;
		int end = N;
		while (start <= end) {
			int mid = start + (end - start >> 1);
			int t = half - mid;
			int lmax1 = mid == 0 ? INT_MIN : nums1[mid - 1];
			int rmin1 = mid == N ? INT_MAX : nums1[mid];
			int lmax2 = t == 0 ? INT_MIN : nums2[t - 1];
			int rmin2 = t == M ? INT_MAX : nums2[t];
			if (lmax1 > rmin2)
				end = mid - 1;
			else if (lmax2 > rmin1)
				start = mid + 1;
			else {
				start = end = mid;
				break;
			}
		}
		int pos1 = start;
		int pos2 = half - start;
		int l = max(
			pos1 == 0 ? INT_MIN : nums1[pos1 - 1],
			pos2 == 0 ? INT_MIN : nums2[pos2 - 1]);
		int r = min(
			pos1 == N ? INT_MAX : nums1[pos1],
			pos2 == M ? INT_MAX : nums2[pos2]);
		if ((N + M) & 1)
			return r;
		return 0.5 * (l + r);
	}
};