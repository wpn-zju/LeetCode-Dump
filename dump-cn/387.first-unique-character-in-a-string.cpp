class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> charMap(30, -1);
		for (int i = 0; i < s.length(); ++i) {
			if (charMap[s[i] - 'a'] == -1)
				charMap[s[i] - 'a'] = i;
			else
				charMap[s[i] - 'a'] = -2;
		}
		int result = INT_MAX;
		for (int i : charMap)
			if (i > -1)
				result = min(result, i);
		return result == INT_MAX ? -1 : result;
	}
};