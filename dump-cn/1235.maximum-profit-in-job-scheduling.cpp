static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int result = 0;
		vector<vector<int>> data{ {0,0} }; // endTime / profit
		vector<vector<int>> jobs; // startTime / endTime / profit
		for (int i = 0; i < startTime.size(); ++i)
			jobs.push_back({ startTime[i], endTime[i], profit[i] });
		sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1]; });
		for (vector<int>& i : jobs) {
			int start = 0;
			int end = data.size() - 1;
			while (start < end) {
				int mid = end - (end - start >> 1);
				if (data[mid][0] > i[0])
					end = mid - 1;
				else
					start = mid;
			}
			if (data.back()[0] == i[1])
				data.back()[1] = max(data.back()[1], data[start][1] + i[2]);
			else if (data.back()[1] < data[start][1] + i[2])
				data.push_back({ i[1], data[start][1] + i[2] });
			result = max(result, data.back()[1]);
		}
		return result;
	}
};