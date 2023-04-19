class Solution {
public:
	int gcd(int x, int y) {
		while (y) swap(y, x %= y);
		return x;
	}

	int mirrorReflection(int p, int q) {
		int l = p * q / gcd(q, p);
		return l / q & 1 ? l / p & 1 ? 1 : 0 : 2;
	}
};