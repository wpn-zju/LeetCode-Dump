class Solution {
public:
	int binaryGap(int N) {
		vector<bool> digits;
		while (N) {
			digits.push_back(N & 1);
			N >>= 1;
		}
		vector<int> one;
		for (int i = 0; i < digits.size(); ++i)
			if (digits[i])
				one.push_back(i);
		int result = 0;
		for (int i = 0; i < one.size() - 1; ++i)
			result = max(result, one[i + 1] - one[i]);
		return result;
	}
};