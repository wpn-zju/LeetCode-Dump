class Solution {
public:
	bool canPermutePalindrome(string s) {
		int m = s.length();
		unordered_map<char, int> map;
		for (char c : s)
			map[c]++;
		bool flag = false;
		for (pair<char,int> i : map)
			if (i.second % 2 == 1)
				if (!flag)
					flag = true;
				else
					return false;
		return true;
	}
};