class Solution {
public:
		void dfs(vector<vector<int>>& result, vector<int>& cur, int start, int end) {
			if (start == end) {
				result.push_back(cur);
				return;
			}
			for (int i = start; i < end; ++i) {
				swap(cur[i], cur[start]);
				dfs(result, cur, start + 1, end);
				swap(cur[i], cur[start]);
			}
		}

		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> result;
			dfs(result, nums, 0, nums.size());
			return result;
		}
};