class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		return nums[start] == target ? start : -1;
	}
};