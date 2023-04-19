class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, string> strMap1;
		unordered_map<string, char> strMap2;
		vector<string> vec;
		int prev = 0;
		int ptr = 0;
		while (ptr < str.length()) {
			while (str[ptr] >= 'a' && str[ptr] <= 'z')
				ptr++;
			vec.push_back(str.substr(prev, ptr - prev));
			prev = ++ptr;
		}
		if (vec.size() != pattern.length())
			return false;
		for (int i = 0; i < vec.size(); ++i) {
			if (strMap1.count(pattern[i]) && strMap1[pattern[i]] != vec[i])
				return false;
			if (strMap2.count(vec[i]) && strMap2[vec[i]] != pattern[i])
				return false;
			strMap1[pattern[i]] = vec[i];
			strMap2[vec[i]] = pattern[i];
		}
		return true;
	}
};