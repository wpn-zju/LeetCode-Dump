class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == INT_MIN)
			return dividend == INT_MIN;
        if(divisor == 1 && dividend == INT_MIN)
            return INT_MIN;
        if(divisor == -1 && dividend == INT_MIN)
            return INT_MAX;
		bool nega = (dividend < 0) ^ (divisor < 0);
        int result = 0;
        if (divisor < 0) divisor = -divisor;
        if(dividend == INT_MIN && (divisor & (divisor - 1)) == 0)
            ++result;
		if (dividend > 0) dividend = -dividend;
		for (int i = 31; i >= 0; --i) {
			if ((divisor >> (31 - i) == 0) && (divisor << i) + dividend <= 0) {
				result += 1 << i;
				dividend += divisor << i;
			}
		}
		return nega ? -result : result;
	}
};