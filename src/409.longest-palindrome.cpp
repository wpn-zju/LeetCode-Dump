class Solution {
public:
	int longestPalindrome(string s) {
		int map[56]{0};
		int count = 0;
		for (char c : s)
			if (c <= 'Z')
				map[c - 'A']++;
			else
				map[c - 'a' + 26]++;
		bool flag = false;
		for (int i : map)
			if (i % 2 == 0)
				count += i;
			else{
				count += i - 1;
                flag = true;
            }

		return count + flag;
	}
};