class Solution {
public:
	int balancedStringSplit(string s) {
		int result = 0;
		int ptr = 0;
		int countL = 0;
		int countR = 0;
		while (ptr < s.length()) {
			if (s[ptr] == 'R') {
				if (++countR == countL) {
					countL = countR = 0;
					++result;
				}
			}
			else {
				if (++countL == countR) {
					countL = countR = 0;
					++result;
				}
			}
            ++ptr;
		}
		return result;
	}
};