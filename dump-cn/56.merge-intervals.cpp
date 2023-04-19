class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int m = intervals.size();
		sort(intervals.begin(), intervals.end());
		int ptr1 = 0;
		int ptr2 = 1;
		int count = m;
		while (ptr2 < m) {
			if (intervals[ptr1][1] >= intervals[ptr2][0]) {
				intervals[ptr1][1] = max(intervals[ptr1][1], intervals[ptr2][1]);
				count--;
			}
			else
                intervals[++ptr1] = intervals[ptr2];
			ptr2++;
		}
		intervals.resize(count);
		return intervals;
	}
};