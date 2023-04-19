class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		unordered_map<int, unordered_set<int>> mySet;
		for (int i = 0; i < points.size(); ++i)
			mySet[points[i][0]].insert(points[i][1]);
		int result = INT_MAX;
		for (int i = 0; i < points.size() - 1; ++i) {
			for (int j = i + 1; j < points.size(); ++j) {
				if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
					continue;
				if (mySet[points[i][0]].count(points[j][1]) && mySet[points[j][0]].count(points[i][1]))
					result = min(result, abs((points[j][1] - points[i][1]) * (points[j][0] - points[i][0])));
			}
		}
		return result == INT_MAX ? 0 : result;
	}
};