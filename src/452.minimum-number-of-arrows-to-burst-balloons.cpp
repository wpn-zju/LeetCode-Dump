class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1]; });
		int count = 0;
		for (int i = 1; i < points.size(); ++i) {
			if (points[i][0] > points[0][1]) {
				points[0][1] = points[i][1];
				count++;
			}
		}
		return points.size() == 0 ? 0 : count + 1;
	}
};