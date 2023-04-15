class Solution {
public:
	int calculateDiff(string& a, string& b) {
		return 60 * ((a[0] - b[0]) * 10 + (a[1] - b[1])) + (a[3] - b[3]) * 10 + (a[4] - b[4]);
	}

	int findMinDifference(vector<string>& timePoints) {
		sort(timePoints.begin(), timePoints.end(), [](string& a, string& b) {
			for (int i = 0; i < 5; ++i)
				if (a[i] != b[i])
					return a[i] < b[i];
			return false;
		});
		timePoints.push_back({ (char)(timePoints[0][0] + 2), (char)(timePoints[0][1] + 4), timePoints[0][2], timePoints[0][3], timePoints[0][4] });
		int mn = INT_MAX;
		for (int i = 0; i < timePoints.size() - 1; ++i)
			mn = min(mn, calculateDiff(timePoints[i + 1], timePoints[i]));
		return mn;
	}
};