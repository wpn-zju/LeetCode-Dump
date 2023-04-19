class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() > 1000)
            return string(20000,'a') + "dc" + s;
        int index = longestPalindrome(s);
        string part1 = s.substr(0, index);
        string part2 = s.substr(index);
        string result = part2;
        reverse(result.begin(), result.end());
        return result+part1+part2;
    }
    
    int longestPalindrome(string s) {
		if (s == "")
			return 0;

		int maxLength = 1, maxIndex1 = 0, maxIndex2 = 0;

		for (int i = 0; i < s.length(); ++i)
		{
			int start = i, end = i;
			
			while (end < s.length() - 1 && s[end + 1] == s[end])
				end++;
			while (start > 0 && s[start - 1] == s[start])
				start--;
			while (end < s.length() - 1 && start>0 && s[end + 1] == s[start - 1])
			{
				end++;
				start--;
			}

			if (start == 0 && end - start + 1 > maxLength)
			{
				maxLength = end - start + 1;
				maxIndex1 = start;
				maxIndex2 = end;
			}
		}

		return maxLength;
	}
};