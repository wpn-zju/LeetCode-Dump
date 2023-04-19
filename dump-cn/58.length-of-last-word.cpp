class Solution {
public:
	int lengthOfLastWord(string s) {
		int ptr = s.length() - 1;
		while (s[ptr] == ' ')
			--ptr;
		int prev = ptr;
		for (; ptr >= 0; --ptr)
			if (s[ptr] == ' ')
				break;
		return s.empty() ? 0 : prev - ptr;
	}
};