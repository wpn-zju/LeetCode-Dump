class Solution {
public:
	unordered_map<string, bool> winMap;
	bool canWin(string& s) {
		if (winMap.count(s))
			return winMap[s];
		if (!s.length())
			return false;
		int ptr = 0;
		while (ptr < s.length() - 1) {
			if (s[ptr] == s[ptr + 1] && s[ptr] == '+') {
				s[ptr] = s[ptr + 1] = '-';
				if (!canWin(s)) {
					s[ptr] = s[ptr + 1] = '+';
					winMap[s] = true;
					return true;
				}
				s[ptr] = s[ptr + 1] = '+';
			}
			ptr++;
		}
		winMap[s] = false;
		return false;
	}
};