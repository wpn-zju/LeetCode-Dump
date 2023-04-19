class Solution {
public:
	int calculateTime(string keyboard, string word) {
		vector<vector<int>> distance(26, vector<int>(26));
		vector<int> pos(26);
		for (int i = 0; i < 26; ++i)
			pos[keyboard[i] - 'a'] = i;
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < 26; ++j)
				distance[i][j] = abs(pos[i] - pos[j]);
		int result = pos[word[0] - 'a'];
		for (int i = 1; i < word.size(); ++i)
			result += distance[word[i - 1] - 'a'][word[i] - 'a'];
		return result;
	}
};