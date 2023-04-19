class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		vector<int> letterMap(26, 0);
		for (char& c : chars)
			letterMap[c - 'a']++;
		int result = 0;
		for (string& str : words) {
			vector<int> copy = vector<int>(letterMap);
			bool flag = false;
			for (char& c : str)
				if (--copy[c - 'a'] < 0) {
					flag = true;
					break;
				}
			if (!flag)
				result += str.size();
		}
		return result;
	}
};