class Solution {
public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> result;
			dfsUnique(result, nums, 0);
			return result;
		}

		void dfsUnique(vector<vector<int>>& result, vector<int>& cur, int start) {
			if (start == cur.size()) {
				result.push_back(cur);
				return;
			}
			for (int i = start; i < cur.size(); i++) {
				// 如果头交换数到尾交换数之间有任何一个数等于尾交换数 则此次作废 因为可能出现相同数字交换后来到头引起的重复计数
				bool flag = false;
				for (int j = start; j < i; ++j)
					if (cur[j] == cur[i])
						flag = true;
				if (flag)
					continue;
				swap(cur[start], cur[i]);
				dfsUnique(result, cur, start + 1);
				swap(cur[i], cur[start]);
			}
		}
};