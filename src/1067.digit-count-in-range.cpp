class Solution {
public:
	int digitsCount(int d, int n) {
		if (n <= 0)
			return 0;
		int tmp = n;
		int result = 0;
		int64_t base = 1;
		if (!d) {
			while (n > 9) {
				if (n % 10)
					result += base * (n / 10);
				else
					result += base * (n / 10 - 1) + (tmp % base) + 1;
				n /= 10;
				base *= 10;
			}
		}
		else {
			while (n) {
				if (n % 10 < d)
					result += base * (n / 10);
				else if (n % 10 == d)
					result += base * (n / 10) + (tmp % base) + 1;
				else
					result += base * (n / 10 + 1);
				n /= 10;
				base *= 10;
			}
		}
		return result;
	}

	int digitsCount(int d, int low, int high) {
		return digitsCount(d, high) - digitsCount(d, low - 1);
	}
};