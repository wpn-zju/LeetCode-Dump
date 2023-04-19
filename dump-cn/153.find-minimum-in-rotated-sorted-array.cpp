static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findMin(vector<int>& nums) {
		int start = 0;
		int end = nums.size() - 1;
		while (start < end) {
			int mid = start + (end - start >> 1);
			if (nums[mid] > nums[end])
				start = mid + 1;
			else
				end = mid;
		}
		return nums[start];
	}
};