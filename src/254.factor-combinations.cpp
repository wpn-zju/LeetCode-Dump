class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		vector<vector<int>> result;
		vector<int> vec;
		getCombinationFractors(result, vec, 2, n);
		return result;
	}

	void getCombinationFractors(vector<vector<int>>& result, vector<int>& cur, int curFactor, int target) {
		for (int i = curFactor; i * i <= target; ++i)
			if (target%i == 0) {
				cur.push_back(i);
				cur.push_back(target / i);
				result.push_back(cur);
				cur.pop_back();
				getCombinationFractors(result, cur, i, target / i);
				cur.pop_back();
			}
	}
};