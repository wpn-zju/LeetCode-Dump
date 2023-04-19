class Solution {
public:
	int countBinarySubstrings(string s) {
		int m = s.length();
		int ptr1 = 0;
		int ptr2 = 0;
		int ptr3 = 1;
		int result = 0;
		bool flag = false;
		while (ptr3 < m) {
			while (!flag && ptr2 < m && s[ptr2] == s[ptr1])
				ptr2++;
			ptr3 = ptr2;
			while (ptr3 < m && s[ptr3] == s[ptr2])
				ptr3++;
			result += min(ptr3 - ptr2, ptr2 - ptr1);
			ptr1 = ptr2;
			ptr2 = ptr3;
			flag = true;
		}
		return result;
	}
};