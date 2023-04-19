class Solution {
public:
	vector<vector<int>> highFive(vector<vector<int>>& items) {
		vector<vector<int>> result(1000);
		for (vector<int>& vec : items)
			result[vec[0]].push_back(vec[1]);
		for (vector<int>& a : result)
			sort(a.begin(), a.end(), greater<int>());
		for (int i = 0; i < result.size() - 1; ++i)
			if (result[i].size())
				result[i] = vector<int>{ i, (result[i][0] + result[i][1] + result[i][2] + result[i][3] + result[i][4]) / 5 };
		vector<vector<int>> output;
		for (vector<int>& a : result)
			if (a.size())
				output.push_back(a);
		return output;
	}
};