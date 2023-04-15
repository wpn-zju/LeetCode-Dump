class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> cur;
		dfsFS(result, nums, cur, 0);
		return result;
	}

	void dfsFS(vector<vector<int>>& result, vector<int>& nums, vector<int>& cur, int index) {
		if (index == nums.size() && cur.size() > 1)
			result.push_back(cur);

		if (index < nums.size()) {
			if (cur.empty() || nums[index] >= cur.back()) {
				cur.push_back(nums[index]);
				dfsFS(result, nums, cur, index + 1);
				cur.pop_back();
			}
			if (cur.empty() || nums[index] != cur.back())
				dfsFS(result, nums, cur, index + 1);
		}
	}
};