static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> result(intervals.size(), -1);
		vector<pair<int, vector<int>>> data;
		for (int i = 0; i < intervals.size(); ++i)
			data.push_back({ i, intervals[i] });
		sort(data.begin(), data.end(), [](pair<int, vector<int>>& a, pair<int, vector<int>>& b) { return a.second[0] < b.second[0]; });
		for (int i = 0; i < intervals.size(); ++i) {
			int start = 0;
			int end = data.size() - 1;
			while (start < end) {
				int mid = start + (end - start >> 1);
				if (data[mid].second[0] < intervals[i][1])
					start = mid + 1;
				else
					end = mid;
			}
			result[i] = data[start].second[0] >= intervals[i][1] ? data[start].first : -1;
		}
		return result;
	}
};