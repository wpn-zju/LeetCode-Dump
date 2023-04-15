class Solution {
public:
	bool isScramble(string s1, string s2) {
		return isScramble(s1, s2, 0, 0, s1.size() - 1, s2.size() - 1);
	}

	bool isScramble(string& s1, string& s2, int start1, int start2, int end1, int end2) {
		bool equal = true;
		for (int i = start1; i <= end1; ++i) {
			if (s1[i] != s2[start2 + i - start1]) {
				equal = false;
				break;
			}
		}
		if (equal)
			return true;
		vector<int> c(26, 0);
		for (int i = start1; i <= end1; ++i) {
			c[s1[i] - 'a']++;
		}
		for (int i = start2; i <= end2; ++i) {
			c[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; ++i)
			if (c[i] != 0)
				return false;
		for (int i = 1; i <= end1 - start1; ++i) {
			if (isScramble(s1, s2, start1, start2, start1 + i - 1, start2 + i - 1) && isScramble(s1, s2, start1 + i, start2 + i, end1, end2))
				return true;
			if (isScramble(s1, s2, start1, end2 - i + 1, start1 + i - 1, end2) && isScramble(s1, s2, start1 + i, start2, end1, end2 - i))
				return true;
		}
		return false;
	}
};