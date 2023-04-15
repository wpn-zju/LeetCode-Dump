class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int L = 0;
		int R = 0;
		int result = 0;
		while (R < s.size()) {
			if (maxCost >= abs(s[R] - t[R])) {
				maxCost -= abs(s[R] - t[R]);
				++R;
				result = max(result, R - L);
			}
			else if (L < R) {
				maxCost += abs(s[L] - t[L]);
				++L;
			}
			else if (L == R) {
				L = ++R;
			}
		}
		return result;
	}
};