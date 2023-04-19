class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (intervals.size() == 0)
			return vector<vector<int>>{newInterval};
		int low = 0;
		int high = intervals.size() - 1;
		int mid = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (intervals[mid][0] < newInterval[0])
				low = mid + 1;
			else if (intervals[mid][0] > newInterval[0])
				high = mid - 1;
			else
				break;
		}
		if (intervals[mid][0] >= newInterval[0])
			intervals.insert(intervals.begin() + mid, newInterval);
		else
			intervals.insert(intervals.begin() + mid + 1, newInterval);
		return merge(intervals);
	}
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int m = intervals.size();
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