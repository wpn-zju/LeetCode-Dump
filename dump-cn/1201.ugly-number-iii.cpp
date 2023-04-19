static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int64_t getGCD(int64_t A, int64_t B) {
		int tmp;
		while (B) {
			tmp = A % B;
			A = B;
			B = tmp;
		}
		return A;
	}

	int64_t calculateFactorSum(int64_t n, int a, int b, int c) {
		int64_t lcm = (int64_t)a * b / getGCD(a, b);
		lcm = lcm * c / getGCD(lcm, c);
		return n / a + n / b + n / c
			- n / ((int64_t)a * b / getGCD(a, b))
			- n / ((int64_t)b * c / getGCD(b, c))
			- n / ((int64_t)a * c / getGCD(a, c))
			+ (n == lcm);
	}

	int nthUglyNumber(int n, int a, int b, int c) {
		if (a == 1 || b == 1 || c == 1)
			return n;
		int64_t lcm = (int64_t)a * b / getGCD(a, b);
		lcm = lcm * c / getGCD(lcm, c);
		int64_t ba = calculateFactorSum(lcm, a, b, c);
		int div = n / ba;
		int mod = n % ba;
		int64_t hi = lcm * div;
		int64_t lo = 0;
		int64_t start = 1;
		int64_t end = lcm;
		while (start < end) {
			int64_t mid = start + (end - start >> 1);
			if (calculateFactorSum(mid, a, b, c) < mod)
				start = mid + 1;
			else
				end = mid;
		}
		int a1 = start / a;
		int b1 = start / b;
		int c1 = start / c;
		lo = max((int64_t)a * a1, (int64_t)b * b1);
		lo = max(lo, (int64_t)c * c1);
		return hi + lo;
	}
};