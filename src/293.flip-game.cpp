class Solution {
public:
	vector<string> generatePossibleNextMoves(string s) {
		if (!s.length())
            return vector<string>();
        vector<string> result;
		int ptr = 0;
		while (ptr < s.length() - 1) {
			if (s[ptr] == s[ptr + 1] && s[ptr] == '+'){
                s[ptr] = s[ptr + 1] = '-';
                result.push_back(s);
                s[ptr] = s[ptr + 1] = '+';
            }
			ptr++;
		}
		return result;
	}
};