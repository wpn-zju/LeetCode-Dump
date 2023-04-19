class Solution {
public:
	int threeSumSmaller(vector<int>& nums, int target) {
		int result = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			int t = target - nums[i];
			int ptr = nums.size() - 1;
			for (int j = i + 1; j < nums.size(); ++j) {
				int t2 = t - nums[j];
				while (ptr > j && nums[ptr] >= t2)
					--ptr;
				if (ptr > j)
					result += ptr - j;
			}
		}
		return result;
	}
};