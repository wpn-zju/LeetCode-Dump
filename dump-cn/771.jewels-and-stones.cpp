class Solution {
public:
	int numJewelsInStones(string J, string S) {
		vector<bool> letterMap(52, false);
		for (char& c : J)
			if (c <= 'Z')
				letterMap[c - 'A' + 26] = true;
			else
				letterMap[c - 'a'] = true;
		int result = 0;
		for (char& c : S)
			if (c <= 'Z' && letterMap[c - 'A' + 26])
				result++;
			else if (c > 'Z' &&letterMap[c - 'a'])
				result++;
		return result;
	}
};