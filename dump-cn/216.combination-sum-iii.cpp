class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
	    vector<vector<int>> result;
	    vector<int> tmp(9);
	    vector<int> vec;
	    for (int i = 0; i < 9; ++i)
		    tmp[i] = i + 1;
	    getCombination3(result, tmp, vec, 0, n, k);
	    return result;
    }

    void getCombination3(vector<vector<int>>& result, vector<int>& candidates, vector<int>& cur, int index, int target, int targetN) {
	    if (cur.size() >= targetN || index >= candidates.size() || candidates[index] > target)
		    return;
	    if (candidates[index] == target && cur.size() == targetN - 1) {
		    cur.push_back(target);
		    result.push_back(cur);
		    cur.pop_back();
		    return;
	    }
	    cur.push_back(candidates[index]);
	    getCombination3(result, candidates, cur, index + 1, target - candidates[index], targetN);
	    cur.pop_back();
	    getCombination3(result, candidates, cur, index + 1, target, targetN);
    }
};