class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> tmp;
		dfsSubset(result, nums, tmp, 0);
		return result;
	}

	void dfsSubset(vector<vector<int>>& result, vector<int>& nums, vector<int>& cur, int index) {
		if (index == nums.size()) {
			result.push_back(cur);
			return;
		}
		// Get
		cur.push_back(nums[index]);
		dfsSubset(result, nums, cur, index + 1);
		cur.pop_back();
		// Not Get
		dfsSubset(result, nums, cur, index + 1);
	}
};