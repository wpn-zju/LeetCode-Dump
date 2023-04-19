class Solution {
public:
	string reverseWords(string s) {
		if (s.empty())
			return s;
		string result = "";
		int prev = s.length() - 1, ptr = s.length() - 1;
		for (;;) {
			while (prev >= 0 && s[prev] == ' ')
				--prev;
			if (prev == -1)
				break;
			ptr = prev - 1;
			while (ptr >= 0 && s[ptr] != ' ')
				--ptr;
			result += s.substr(ptr + 1, prev - ptr) + ' ';
			prev = ptr;
		}
		if (!result.empty())
			result.pop_back();
		return result;
	}
};