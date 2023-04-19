class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> tmp;
		getCombination1(result, candidates, tmp, 0, target);
		return result;
	}

	void getCombination1(vector<vector<int>>& result, vector<int>& candidates, vector<int>& cur, int index, int target) {
        // 越界或溢出 返回
		if (index >= candidates.size() || candidates[index] > target)
			return;
        // 符合条件的结果
		if (candidates[index] == target) {
			cur.push_back(target);
			result.push_back(cur);
			cur.pop_back();
			return;
		}
        // Case 1 选当前数 没问题
		cur.push_back(candidates[index]);
		getCombination1(result, candidates, cur, index + 1, target - candidates[index]);
		cur.pop_back();
        // Case 2 不选当前数 则后面若干个和当前数相同的数也不能选 直接跳到后面第一个不相同的数
        while(index < candidates.size() - 1 && candidates[index] == candidates[index + 1])
            index++;
        getCombination1(result, candidates, cur, index + 1, target);
	}
};