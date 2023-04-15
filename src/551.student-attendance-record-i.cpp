class Solution {
public:
	bool checkRecord(string s) {
		if (s.length() < 2)
			return true;
		if (s[0] == 'A' && s[1] == 'A')
			return false;
		bool ab = s[0] == 'A' || s[1] == 'A';
		for (int i = 2; i < s.length(); ++i)
			if (s[i] == 'A')
				if (ab)
					return false;
				else
					ab = true;
			else if (s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')
				return false;
		return true;
	}
};