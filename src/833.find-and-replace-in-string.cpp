class Solution {
public:
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		string result = "";
		unordered_map<int, int> match;
		for (int i = 0; i < indexes.size(); ++i)
			match[indexes[i]] = i;
		for (int i = 0; i < S.size(); ++i) {
			if (match.count(i) && S.substr(i, sources[match[i]].size()) == sources[match[i]]) {
				result += targets[match[i]];
				i += sources[match[i]].size() - 1;
			}
			else
				result += S[i];
		}
		return result;
	}
};