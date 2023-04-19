class Solution {
public:
	int consecutiveNumbersSum(int N) {
		int count = 0;
		for (int d = sqrt(2 * N); d >= 1; --d)
			if ((2 * N + d - d * d) % (2 * d) == 0)
				++count;
		return count;
	}
};