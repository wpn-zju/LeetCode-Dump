class Solution {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		vector<unordered_set<int>> match(26 * 26);
		for (string& str : allowed) {
			int a = str[0] - 'A';
			int b = str[1] - 'A';
			int t = str[2] - 'A';
			match[a * 26 + b].insert(t);
		}
		bool result = false;
		string tmp = "";
		dfsFindPyramid(result, match, bottom, tmp, 0);
		return result;
	}

	void dfsFindPyramid(bool& result, vector<unordered_set<int>>& match, string cur, string next, int index) {
        if (result)
			return;
		if (index + 1 == cur.size()) {
			index = 0;
			cur = move(next);
			if (cur.size() == 1) {
				result = true;
				return;
			}
		}
		for (int i : match[(cur[index] - 'A') * 26 + cur[index + 1] - 'A']) {
			dfsFindPyramid(result, match, cur, next + char(i + 'A'), index + 1);
		}
	}
};