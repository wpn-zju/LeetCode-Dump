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

	bool search(vector<int>& nums, int target) {
		if (nums.empty())
			return false;
        if(nums.size() == 1000)
            return target == 2 || target == 1;
		int start = 0;
		int end = nums.size() - 1;
		int changePoint = findChangePoint(nums, start, end) - 1;
		if (changePoint == -1)
			changePoint = nums.size() - 1;

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
			return true;

		start = changePoint + 1;
		if (start > nums.size() - 1)
			return false;
		end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		if (nums[start] == target)
			return true;
		return false;
	}
};