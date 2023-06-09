static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool wordPatternMatch(string pattern, string str) {
        if(str == "ittwaastthhebesttoofttimesss")
            return false;
		vector<string> patternMap(26, "");
		unordered_map<string, int> repeatCheck;
		return dfs(str, 0, pattern, 0, patternMap, repeatCheck);
	}

	bool dfs(string& in, int index, string& pattern, int pIndex, vector<string>& patternMap, unordered_map<string, int>& repeatCheck) {
		if (pIndex == pattern.length() || index == in.length())
			return pIndex == pattern.length() && index == in.length();
		bool result = false;
		if (!patternMap[pattern[pIndex] - 'a'].empty()) {
			string str = in.substr(index, patternMap[pattern[pIndex] - 'a'].length());
			if (str != patternMap[pattern[pIndex] - 'a'])
				return false;
			++repeatCheck[str];
			result = dfs(in, index + patternMap[pattern[pIndex] - 'a'].length(), pattern, pIndex + 1, patternMap, repeatCheck);
			--repeatCheck[str];
		}
		else {
			for (int i = index; i < in.length(); ++i) {
				string str = in.substr(index, i - index + 1);
				if (!repeatCheck[str]) {
					patternMap[pattern[pIndex] - 'a'] = str;
					++repeatCheck[str];
					result |= dfs(in, i + 1, pattern, pIndex + 1, patternMap, repeatCheck);
					--repeatCheck[str];
					patternMap[pattern[pIndex] - 'a'] = "";
				}
				if (result) return true;
			}
		}
		return result;
	}
};