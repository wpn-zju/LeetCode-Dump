class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> result(nums.size());
		vector<pair<int, int>> wp;
		for (int i = 0; i < nums.size(); ++i)
			wp.push_back({ nums[i], i });
		sort(wp.begin(), wp.end(), greater<pair<int, int>>());
		if (nums.size() > 0)
			result[wp[0].second] = "Gold Medal";
		if (nums.size() > 1)
			result[wp[1].second] = "Silver Medal";
		if (nums.size() > 2)
			result[wp[2].second] = "Bronze Medal";
		for (int i = 3; i < wp.size(); ++i)
			result[wp[i].second] = to_string(i + 1);
		return result;
	}
};