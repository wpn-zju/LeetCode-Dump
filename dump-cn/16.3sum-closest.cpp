class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int minDiff = INT_MAX;
		int minSum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int start = i + 1;
			int end = nums.size() - 1;
			while (start < end) {
				int sum = nums[i] + nums[start] + nums[end];
				if (abs(target - sum) < minDiff) {
					minDiff = abs(target - sum);
					minSum = sum;
				}
				if (sum < target)
					start++;
				else if (sum > target)
					end--;
				else
					return target;
			}
		}
		return minSum;
	}
};