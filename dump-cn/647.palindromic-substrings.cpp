class Solution {
public:
	int countSubstrings(string s) {
		int result = 0;
		for (int i = 0; i < s.length(); ++i) {
			result += count2(s, i, i);
			result += count2(s, i, i + 1);
		}
		return result;
	}

	int count2(string& s, int start, int end) {
		int result = 0;
		while (start >= 0 && end < s.length() && s[start--] == s[end++])result++;
		return result;
	}
};