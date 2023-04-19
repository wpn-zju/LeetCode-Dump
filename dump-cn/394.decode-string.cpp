class Solution {
public:
	string decodeString(string s) {
		stack<int> times;
		stack<string> contents;
		int len = 0;
		string cur = "";
		for (int ptr = 0; ptr != s.length(); ++ptr) {
			if (s[ptr] == '[') {
				times.push(len);
				contents.push(cur);
				len = 0;
				cur = "";
			}
			else if (s[ptr] == ']') {
				string tmpStr = contents.top();
				for (int i = 0; i < times.top(); ++i)
					tmpStr += cur;
				cur = tmpStr;
				times.pop();
				contents.pop();
			}
			else if (s[ptr] >= '0' && s[ptr] <= '9') {
				len *= 10;
				len += s[ptr] - '0';
			}
			else
				cur.push_back(s[ptr]);
		}
		return cur;
	}
};