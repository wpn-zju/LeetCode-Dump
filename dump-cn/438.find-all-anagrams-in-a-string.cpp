class Solution {
public:
    bool compareArray(int* a, int* b, int size = 26) {
		while (--size)
			if (*(a + size) != *(b + size))
				return false;
		return true;
	}
    
	vector<int> findAnagrams(string s, string p) {
		vector<int> result;
		int m = s.length();
		int n = p.length();
        if(m == 0 || m < n)
            return result;
		int sArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int pArray[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (char c : p)
			pArray[c - 'a']++;
		for (int i = 0; i < n; ++i)
			sArray[s[i] - 'a']++;
		if (compareArray(sArray, pArray))
			result.push_back(0);
		int ptr = 1;
		while (ptr <= m - n) {
			sArray[s[ptr - 1] - 'a']--;
			sArray[s[ptr + n - 1] - 'a']++;
			if (compareArray(sArray, pArray))
				result.push_back(ptr);
			ptr++;
		}
		return result;
	}
};