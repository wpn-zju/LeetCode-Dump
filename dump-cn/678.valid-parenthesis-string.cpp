class Solution {
public:
	bool checkValidString(string s) {
		int lC = 0, rC = 0, sC = 0;
		for (int i = 0; i < s.length(); ++i) {
			switch (s[i]) {
			case '(':
				++lC;
				break;
			case ')':
				++rC;
				if (rC > lC) {
					sC -= rC - lC;
					if (sC < 0)
						return false;
					lC = rC;
				}
				break;
			case '*':
				++sC;
				break;
			}
		}
		if (abs(lC - rC) > sC)
			return false;
		lC = rC = sC = 0;
		for (int i = s.length() - 1; i >= 0; --i) {
			switch (s[i]) {
			case '(':
				++lC;
				if (lC > rC) {
					sC -= lC - rC;
					if (sC < 0)
						return false;
					rC = lC;
				}
				break;
			case ')':
				++rC;
				break;
			case '*':
				++sC;
				break;
			}
		}
		return abs(lC - rC) <= sC;
	}
};