class Solution {
public:
	void reverseWords(vector<char>& s) {
		reverse(s.begin(), s.end());
		int prev = 0;
		int ptr = 0;
		while (ptr < s.size()) {
			while (ptr < s.size() && s[ptr] != ' ')
				++ptr;
			reverse(s.begin() + prev, s.begin() + ptr);
			prev = ++ptr;
			++ptr;
		}
	}
};