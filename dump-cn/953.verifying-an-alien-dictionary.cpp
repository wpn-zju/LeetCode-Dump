class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		vector<char> charMap(26);
		for (int i = 0; i < order.size(); ++i)
			charMap[order[i] - 'a'] = i + 'a';
		for (int i = 0; i < words.size(); ++i) {
			for (char& c : words[i])
				c = charMap[c - 'a'];
			if (i > 0 && words[i] < words[i - 1])
				return false;
		}
		return true;
	}
};