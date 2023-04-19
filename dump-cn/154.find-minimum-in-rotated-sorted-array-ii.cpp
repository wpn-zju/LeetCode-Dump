static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findChangePoint(vector<int>& nums, int start, int end) {
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] == nums[end])
				--end;
			else if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
    
	int findMin(vector<int>& nums) {
		return nums[findChangePoint(nums, 0, nums.size() - 1)];
	}
};