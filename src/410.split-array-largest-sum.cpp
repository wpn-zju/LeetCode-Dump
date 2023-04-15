class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int64_t sum = 0;
		int mx = INT_MIN;
		for (int& i : nums) {
			sum += i;
			mx = max(i, mx);
		}
		int start = mx;
		int end = sum;
		while (start < end) {
			int mid = start + (end - start >> 1);
			int cur = 0;
			int count = 1;
			for (int& i : nums) {
				cur += i;
				if (cur > mid) {
					cur = i;
					++count;
				}
			}
			if (count > m)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};