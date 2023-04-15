class Solution {
public:
	void charShift(char& c, int& i) {
		c += i - 26;
		if (c < 'a')
			c += 26;
	}

	string shiftingLetters(string S, vector<int>& shifts) {
		int sum = 0;
		for (int i = shifts.size() - 1; i >= 0; --i)
			charShift(S[i], (sum += shifts[i]) %= 26);
		return S;
	}
};