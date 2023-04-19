class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (!nums.size())
			return 0;

		sort(nums.begin(), nums.end());
		unordered_map<int, int> myMap;
		vector<int> tmp;
		for (int& i : nums) {
			myMap[i]++;
			if (tmp.empty() || i > tmp.back())
				tmp.push_back(i);
		}

		vector<int> dp(tmp.size() + 1, 0);
		dp[0] = 0;
		dp[1] = tmp[0] * myMap[tmp[0]];
		for (int i = 1; i < tmp.size(); ++i)
			if (tmp[i] > tmp[i - 1] + 1)
				dp[i + 1] = dp[i] + tmp[i] * myMap[tmp[i]];
			else
				dp[i + 1] = max(dp[i], tmp[i] * myMap[tmp[i]] + dp[i - 1]);
		return dp.back();
	}
};