class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
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
		// Not Get 不加时加下面两行代码跳过相同值 => index处不取 则后面与index相同的都不能取
		while (index < nums.size() - 1 && nums[index] == nums[index + 1])
			index++;
		dfsSubset(result, nums, cur, index + 1);
	}
};