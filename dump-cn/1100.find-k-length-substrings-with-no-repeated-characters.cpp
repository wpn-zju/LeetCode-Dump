class Solution {
public:
	int numKLenSubstrNoRepeats(string S, int K) {
		if (K > 26)
			return 0;
		int result = 0;
		vector<bool> count(26, false);
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr2 < S.size()) {
			if (!count[S[ptr2] - 'a']) {
				count[S[ptr2] - 'a'] = true;
				if (ptr2 - ptr1 == K - 1) {
					++result;
					count[S[ptr1++] - 'a'] = false;
				}
			}
			else {
				while (S[ptr1] != S[ptr2])
					count[S[ptr1++] - 'a'] = false;
				++ptr1;
			}
			++ptr2;
		}
		return result;
	}
};