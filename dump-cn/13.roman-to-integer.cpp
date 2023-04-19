static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int romanToInt2(string& s, int start) {
		int result = 0;
		if (start < s.length())
			switch (s[start])
			{
			case 'I':
				if (start == s.length() - 1 || s[start + 1] != 'V' && s[start+1] != 'X')
					result += 1 + romanToInt2(s, start + 1);
				else if (s[start+1] == 'V')
					result += 4 + romanToInt2(s, start + 2);
				else
					result += 9 + romanToInt2(s, start + 2);
				break;
			case 'V':
				result += 5 + romanToInt2(s, start + 1);
				break;
			case 'X':
				if (start == s.length() - 1 || s[start+1] != 'L' && s[start+1] != 'C')
					result += 10 + romanToInt2(s, start + 1);
				else if (s[start+1] == 'L')
					result += 40 + romanToInt2(s, start + 2);
				else
					result += 90 + romanToInt2(s, start + 2);
				break;
			case 'L':
				result += 50 + romanToInt2(s, start + 1);
				break;
			case 'C':
				if (start == s.length() - 1 || s[start+1] != 'D' && s[start+1] != 'M')
					result += 100 + romanToInt2(s, start + 1);
				else if (s[start+1] == 'D')
					result += 400 + romanToInt2(s, start + 2);
				else
					result += 900 + romanToInt2(s, start + 2);
				break;
			case 'D':
				result += 500 + romanToInt2(s, start + 1);
				break;
			case 'M':
				result += 1000 + romanToInt2(s, start + 1);
				break;
			}
		return result;
	}

	int romanToInt(string& s) {
		return romanToInt2(s, 0);
	}
};