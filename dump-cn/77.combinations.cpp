class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> total;
		vector<int> temp;
		for (int i = 0; i < n; ++i)
			total.push_back(i);
		dfsCombine(result, total, temp, 0, k);
		return result;
	}

	void dfsCombine(vector<vector<int>>& result, vector<int>& t, vector<int>& a, int step, int targetNum) {
		if (a.size() == targetNum) {
			result.push_back(a);
			return;
		}
		if (step >= t.size())
			return;
		a.push_back(t[step] + 1);
		dfsCombine(result, t, a, step + 1, targetNum);
		a.pop_back();
		dfsCombine(result, t, a, step + 1, targetNum);
	}
};