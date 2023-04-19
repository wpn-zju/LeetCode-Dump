class Solution {
public:
	int missingElement(vector<int>& nums, int k) {
        nums.push_back(INT_MAX);
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] - nums[0] - mid < k)
				start = mid + 1;
			else
				end = mid;
		}
		return nums[start - 1] + (k - nums[start - 1] + nums[0] + start - 1);
	}
};