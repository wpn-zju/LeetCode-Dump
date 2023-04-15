class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
		int count = 0;
		for (int i = 1; i < intervals.size(); ++i) {
			if (intervals[i][0] < intervals[0][1]) {
				intervals[0][1] = min(intervals[i][1], intervals[0][1]);
				count++;
			}
			else
				intervals[0][1] = intervals[i][1];
		}
		return count;
	}
};