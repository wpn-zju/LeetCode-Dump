static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end = mid;
		}
		int changePoint = start - 1;
		start = 0;
		end = changePoint;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (nums[start] == target)
			return start;
		start = changePoint + 1;
		end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (nums[start] == target)
			return start;
		return -1;
	}
};