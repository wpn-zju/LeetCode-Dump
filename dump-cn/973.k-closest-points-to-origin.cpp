class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& words, int k) {
		sort(words.begin(), words.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
		});
		vector<vector<int>> result;
		for (vector<int>& vec : words)
			if (result.size() < k)
				result.push_back(vec);
			else
				break;
		return result;
	}
};