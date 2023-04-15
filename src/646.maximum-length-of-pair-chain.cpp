class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) { return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1]; });
		int result = 0;
		int last = INT_MIN;
		for (int i = 0; i < pairs.size(); ++i) {
			if (pairs[i][0] > last) {
				last = pairs[i][1];
				result++;
			}
		}
		return result;
	}
};