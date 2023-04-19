class Solution {
public:
	bool isIsomorphic(string& s, string& t) {
		vector<char> charMap1(130, 0);
		vector<char> charMap2(130, 0);
		for (int i = 0; i < s.length(); ++i) {
			if (charMap1[s[i]] && charMap1[s[i]] != t[i])
				return false;
			if (charMap2[t[i]] && charMap2[t[i]] != s[i])
				return false;
			charMap1[s[i]] = t[i];
			charMap2[t[i]] = s[i];
		}
		return true;
	}

	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> result;
		for (string& str : words)
			if (isIsomorphic(str, pattern))
				result.push_back(str);
		return result;
	}
};