class Solution {
public:
	string reverseVowels(string s) {
		unordered_set<char> charSet{ 'a','e','i','o','u','A','E','I','O','U' };
		int ptr1 = 0;
		int ptr2 = s.size() - 1;
		while (ptr1 < ptr2) {
			while (ptr1 < ptr2&&charSet.count(s[ptr1]) == 0)
				ptr1++;
			while (ptr1 < ptr2&&charSet.count(s[ptr2]) == 0)
				ptr2--;
			char tmp = s[ptr1];
			s[ptr1] = s[ptr2];
			s[ptr2] = tmp;
			ptr1++;
			ptr2--;
		}
		return s;
	}
};