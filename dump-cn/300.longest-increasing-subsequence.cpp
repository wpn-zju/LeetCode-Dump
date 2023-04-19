static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int binarySearch(vector<int>& nums, int length, int& target) {
		int start = 0;
		int end = length - 1;
		while (start < end) {
			int mid = (start + end) / 2;
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}

	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int length = 1;
		for (int i = 1; i < nums.size(); ++i){
 			if (nums[i] > nums[length - 1])
				nums[length++] = nums[i];
            else
                nums[binarySearch(nums, length, nums[i])] = nums[i];
        }
		return length;
	}
};