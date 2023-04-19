class Solution {
public:
	string removeVowels(string S) {
		unordered_set<char> charSet{ 'a','e','i','o','u','A','E','I','O','U' };
		int m = S.size();
		int ptr1 = 0;
		int ptr2 = 0;
		int countVowel = 0;
		while (ptr2 < m) {
			if (charSet.count(S[ptr2]) == 0) {
				S[ptr1] = S[ptr2];
				ptr1++;
				ptr2++;
			}
			else {
				ptr2++;
				countVowel++;
			}
		}
		S.resize(m - countVowel);
		return S;
	}
};