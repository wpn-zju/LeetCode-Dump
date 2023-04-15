class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int result = 0;
		vector<bool> visited(nums.size(), false);
		for (int i = 0; i < nums.size(); ++i)
			dfsArray(nums, visited, i, 0, result);
		return result;
	}

	void dfsArray(vector<int>& nums, vector<bool>& visited, int cur, int length, int& result) {
		if (visited[cur]) {
			result = max(result, length);
			return;
		}
		visited[cur] = true;
		dfsArray(nums, visited, nums[cur], length + 1, result);
	}
};