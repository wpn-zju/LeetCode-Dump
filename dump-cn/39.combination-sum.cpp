class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> tmp;
		getCombination1(result, candidates, tmp, 0, target);
		return result;
	}

	void getCombination1(vector<vector<int>>& result, vector<int>& candidates, vector<int>& cur, int index, int target) {
		if (index >= candidates.size() || candidates[index] > target)
			return;
		if (candidates[index] == target) {
			cur.push_back(target);
			result.push_back(cur);
			cur.pop_back();
			return;
		}
		cur.push_back(candidates[index]);
		getCombination1(result, candidates, cur, index, target - candidates[index]);
		cur.pop_back();
		getCombination1(result, candidates, cur, index + 1, target);
	}
};