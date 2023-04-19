class Solution {
public:
	vector<int> readLogs(string& str) {
		vector<int> result(3, 0);
		int len = 0;
		int ptr = 0;
		while (str[ptr] >= '0' && str[ptr] <= '9') {
			len *= 10;
			len += str[ptr] - '0';
			++ptr;
		}
		result[0] = len;
		len = 0;
		++ptr;
		result[1] = str[ptr] == 's';
		ptr += result[1] ? 6 : 4;
		len = 0;
		while (ptr < str.length()) {
			len *= 10;
			len += str[ptr] - '0';
			++ptr;
		}
		result[2] = result[1] ? len : len + 1;
		return result;
	}

	vector<int> exclusiveTime(int n, vector<string>& logs) {
		vector<int> result(n, 0);
		vector<vector<int>> log;
		for (string& str : logs)
			log.push_back(readLogs(str));
		int last = 0;
		stack<int> s;
		for (vector<int>& vec : log) {
			if (vec[1]) {
				if (!s.empty())
					result[s.top()] += vec[2] - last;
				s.push(vec[0]);
			}
			else {
				result[vec[0]] += vec[2] - last;
				s.pop();
			}
			last = vec[2];
		}
		return result;
	}
};