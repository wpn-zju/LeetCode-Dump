class Solution {
public:
	void reverseString(vector<char>& s) {
		int m = s.size();
		int ptr = 0;
		while (ptr < m - ptr - 1) {
			char tmp = s[ptr];
			s[ptr] = s[m - ptr - 1];
			s[m - ptr - 1] = tmp;
            ptr++;
		}
	}
};