class Solution {
public:
    bool compareArray(int* a, int* b, int size = 26) {
		while (--size)
			if (*(a + size) != *(b + size))
				return false;
		return true;
	}
    
	bool checkInclusion(string s1, string s2) {
		int m = s1.size();
		int n = s2.size();
		int cArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int sArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int ptr = 0;
		if (n < m)
			return false;
		for (int i = 0; i < m; ++i) {
			cArray[s2[i] - 'a']++;
			sArray[s1[i] - 'a']++;
		}
		if (compareArray(cArray, sArray))
			return true;
		while (ptr < n - m) {
			cArray[s2[ptr] - 'a']--;
			cArray[s2[ptr + m] - 'a']++;
			if (compareArray(cArray, sArray))
				return true;
			ptr++;
		}
		return false;
	}
};