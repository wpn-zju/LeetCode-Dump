static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		vector<vector<int>> result;
		sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });
		for (vector<int>& vec : people)
			result.insert(result.begin() + vec[1], vec);
		return result;
	}
};