class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())
            return nums;
		sort(nums.begin(), nums.end());
		vector<int> dp(nums.size(), 0);
		vector<int> path(nums.size(), -1);
		for (int i = 0; i < nums.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (nums[i] % nums[j] == 0) {
					if (dp[j] + 1 > dp[i]) {
						dp[i] = dp[j] + 1;
						path[i] = j;
					}
				}
			}
		}
		int mx = 0;
		int mxI = 0;
		for (int i = 0; i < dp.size(); ++i) {
			if (dp[i] > mx) {
				mx = dp[i];
				mxI = i;
			}
		}
		vector<int> result;
		int cur = mxI;
		while (cur != -1) {
			result.push_back(nums[cur]);
			cur = path[cur];
		}
		return result;
	}
};