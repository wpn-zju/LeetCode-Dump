class Solution {
public:
	int longestDecomposition(string text) {
		int result = 1;
		int ptrL = 0;
		int ptrR = text.length() - 1;
		int prev = ptrL - 1;
		int post = ptrR + 1;
		while (ptrL < ptrR) {
			if (text.substr(prev + 1, ptrL - prev) == text.substr(ptrR, post - ptrR)) {
				result += 2;
				prev = ptrL;
				post = ptrR;
			}
			ptrL++;
			ptrR--;
		}
		if (prev == ptrL - 1 && ptrR < ptrL)
			result--;
		return result;
	}
};