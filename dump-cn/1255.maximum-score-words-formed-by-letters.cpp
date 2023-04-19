class Solution {
public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		vector<int> scores(words.size(), 0);
		for (int i = 0; i < words.size(); ++i) {
			int tmp = 0;
			for (char& c : words[i])
				tmp += score[c - 'a'];
			scores[i] = tmp;
		}
		int result = 0;
		vector<int> cur(26, 0);
		for (char& c : letters)
			++cur[c - 'a'];
		dfsFindMSW(words, result, scores, cur, 0, 0);
		return result;
	}

	void dfsFindMSW(vector<string>& words, int& result, vector<int>& scores, vector<int>& cur, int curScore, int index) {
		if (index == words.size()) {
			result = max(result, curScore);
			return;
		}
		dfsFindMSW(words, result, scores, cur, curScore, index + 1);
		bool valid = true;
		for (int i = 0; i < words[index].size(); ++i)
			if (--cur[words[index][i] - 'a'] < 0)
				valid = false;
		if (valid)
			dfsFindMSW(words, result, scores, cur, curScore + scores[index], index + 1);
		for (int i = 0; i < words[index].size(); ++i)
			++cur[words[index][i] - 'a'];
	}
};