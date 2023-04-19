class Solution {
public:
	string reverseWords(string s) {
		int m = s.size();
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 < m) {
			while (ptr2 < m && s[ptr2] != ' ')
                ptr2++;
			reverse(s.begin() + ptr1, s.begin() + ptr2);
			ptr2++;
            ptr1 = ptr2;
		}
		return s;
	}
};