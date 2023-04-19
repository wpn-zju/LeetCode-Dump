class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int start = 0;
		int end = nums.size() - 1;
        int mid;
		while (start < end) {
			mid = start + (end - start >> 1);
			if ((end - start >> 1) & 1) {
				if (nums[mid] == nums[mid - 1])
					start = mid + 1;
				else
					end = mid - 1;
			}
			else {
				if (nums[mid] == nums[mid - 1])
					end = mid - 2;
				else
					start = mid;
			}
		}
		return nums[start];
	}
};