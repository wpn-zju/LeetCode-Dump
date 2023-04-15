class Solution {
public:
	int longestMountain(vector<int>& A) {
		int m = A.size();
		if (m < 3)
			return 0;
		int ptrL = 0;
		int ptrM = 0;
		int ptrR = 0;
		int result = 0;
		while (ptrR < m) {
			while (ptrM < m - 1 && A[ptrM + 1] > A[ptrM])
				ptrM++;
			ptrR = ptrM;
			while (ptrR < m - 1 && A[ptrR + 1] < A[ptrR])
				ptrR++;
			if (ptrL != ptrM && ptrR != ptrM && result < ptrR - ptrL + 1)
				result = ptrR - ptrL + 1;
            if(ptrL == ptrR)
                ptrL = ptrM = ++ptrR;
            else
                ptrL = ptrM = ptrR;
		}
		return result;
	}
};