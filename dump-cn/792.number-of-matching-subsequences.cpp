static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool isMatched(string& S, string& str) {
		int i = 0, j = 0;
		while (i < str.size() && j < S.size()){
			if (str[i] == S[j])
				++i;            
            ++j;
        }
		return i == str.size();
	}

	int numMatchingSubseq(string S, vector<string>& words) {
		unordered_map<string, int> wordsMap;
		for (string& str : words)
			++wordsMap[str];
		int count = 0;
		for (pair<string, int> str : wordsMap)
			if (isMatched(S, str.first))
				count += str.second;
		return count;
	}
};