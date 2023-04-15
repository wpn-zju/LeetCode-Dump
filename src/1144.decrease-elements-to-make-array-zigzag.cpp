class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		vector<int> t = nums;
		int result1 = 0;
		int result2 = 0;
		// first ascending
		for (int i = 0; i < nums.size() - 1; ++i) {
			if (i & 1) {
				if (nums[i] <= nums[i + 1]) {
					result1 += nums[i + 1] - nums[i] + 1;
					nums[i + 1] = nums[i] - 1;
				}
			}
			else {
				if (nums[i] >= nums[i + 1]) {
					result1 += nums[i] - nums[i + 1] + 1;
					nums[i] = nums[i + 1] - 1;
				}
			}
		}
		// first descending
		for (int i = 0; i < t.size() - 1; ++i) {
			if (i & 1) {
				if (t[i] >= t[i + 1]) {
					result2 += t[i] - t[i + 1] + 1;
					t[i] = t[i + 1] - 1;
				}
			}
			else {
				if (t[i] <= t[i + 1]) {
					result2 += t[i + 1] - t[i] + 1;
					t[i + 1] = t[i] - 1;
				}
			}
		}
		return min(result1, result2);
	}
};