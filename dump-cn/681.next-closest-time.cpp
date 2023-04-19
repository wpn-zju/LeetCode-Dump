class Solution {
public:
	int calculateDiff(string& a, string& b) {
		return 60 * ((a[0] - b[0]) * 10 + (a[1] - b[1])) + (a[3] - b[3]) * 10 + (a[4] - b[4]);
	}

	string nextClosestTime(string time) {
		unordered_set<string> data;
		vector<char> letters{ time[0],time[1], time[3],time[4] };
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				for (int k = 0; k < 4; ++k)
					for (int l = 0; l < 4; ++l) {
						string cur{ letters[i], letters[j],':',letters[k], letters[l] };
						if (cur[3] - '0' > 5 || (cur[0] - '0') * 10 + cur[1] - '0' > 23)
							continue;
						data.insert(cur);
					}
		string result = "";
		int dis = INT_MAX;
		for (string str : data) {
			int diff = calculateDiff(str, time);
			if (diff <= 0)
				diff += 1440;
			if (diff < dis) {
				dis = diff;
				result = str;
			}
		}
		return result;
	}
};