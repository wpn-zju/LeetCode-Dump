class Solution {
public:
	int getGCD(int A, int B) {
		int tmp;
		while (B) {
			tmp = A % B;
			A = B;
			B = tmp;
		}
		return A;
	}

	int nthMagicalNumber(int N, int A, int B) {
		int lcm = A * B / getGCD(A, B);
		int b = lcm / A + lcm / B - 1;
		int mod = N % b;
		int div = N / b;
		int64_t lo = (int64_t)lcm * div;
		int hi = 0;
		int64_t start = 1;
		int64_t end = A * B;
		while (start < end) {
			int64_t mid = start + (end - start >> 1);
			if (mid / A + mid / B < mod)
				start = mid + 1;
			else
				end = mid;
		}
		int a1 = start / A;
		int b1 = start / B;
		hi = max(A * a1, B * b1);
		return (lo + hi) % 1000000007;
	}
};