class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> bannedSet;
		unordered_map<string, int> count;
		for (string& str : banned) {
			bannedSet.insert(str);
		}
		paragraph += ' ';
		int ptr = 0;
		for (int i = 0; i < paragraph.size(); ++i) {
			if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
				paragraph[i] += 'a' - 'A';
			}
			if (paragraph[i] < 'a' || paragraph[i] >'z') {
				if (ptr != i) {
					++count[paragraph.substr(ptr, i - ptr)];
				}
				ptr = i + 1;
			}
		}
		int mx = 0;
		string result = "";
		for (auto it = count.begin(); it != count.end(); ++it) {
			if (it->second > mx && !bannedSet.count(it->first)) {
				mx = it->second;
				result = it->first;
			}
		}
		return result;
	}
};