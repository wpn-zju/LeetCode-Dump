class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
		int temp = 0;
		map<char, int> charMap;

		for (int i = 0; i < s.length(); ++i)
		{
			temp = i + 1 - charMap[s[i]] > temp ? temp + 1 : i + 1 - charMap[s[i]];
			charMap[s[i]] = i + 1;
			max = temp > max ? temp : max;
		}

		return max;
    }
};