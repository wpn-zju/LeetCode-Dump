static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findLeft(vector<int>& nums, int& target) {
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start) / 2;
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		return nums[start] == target ? start : -1;
	}

	int findRight(vector<int>& nums, int& target) {
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start + 1) / 2;
			if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid;
		}
		return nums[start] == target ? start : -1;
	}

	bool isMajorityElement(vector<int>& nums, int target) {
		if (nums.size() == 1)
			return target == nums[0];
		return findRight(nums, target) - findLeft(nums, target) + 1 > nums.size() / 2;
	}
};