static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		vector<int> result(queries.size(), -1);
		vector<vector<int>> searchMap(3, vector<int>());
		for (int i = 0; i < colors.size(); ++i)
			searchMap[colors[i] - 1].push_back(i);
		for (int i = 0; i < queries.size(); ++i) {
			if (!searchMap[queries[i][1] - 1].empty()) {
				vector<int>& v = searchMap[queries[i][1] - 1];
				int start = 0;
				int end = v.size() - 1;
				while (start < end) {
					int mid = start + (end - start >> 1);
					if (v[mid] < queries[i][0])
						start = mid + 1;
					else
						end = mid;
				}
				result[i] = start ? min(abs(v[start] - queries[i][0]), abs(queries[i][0] - v[start - 1])) : abs(v[0] - queries[i][0]);
			}
		}
		return result;
	}
};