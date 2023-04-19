class Solution {
public:
	string shortestCompletingWord(string licensePlate, vector<string>& words) {
		vector<pair<int, int>> licenseMap(26);
		for (int i = 0; i < 26; ++i)
			licenseMap[i] = { i,0 };
		for (char& c : licensePlate) {
			if (c >= 'a'&&c <= 'z')
				licenseMap[c - 'a'].second++;
			else if (c >= 'A'&&c <= 'Z')
				licenseMap[c - 'A'].second++;
		}
		string result = "";
		for (string& str : words) {
			vector<pair<int, int>> patternMap(26);
			for (char& c : str) {
				if (c >= 'a'&&c <= 'z')
					patternMap[c - 'a'].second++;
				else if (c >= 'A'&&c <= 'Z')
					patternMap[c - 'A'].second++;
			}
			bool tag = true;
			for (int i = 0; i < 26; ++i) {
				if (patternMap[i].second < licenseMap[i].second) {
					tag = false;
					break;
				}
			}
			if (tag)
				if (str.length() < result.length() || !result.length())
					result = str;
		}
		return result;
	}
};