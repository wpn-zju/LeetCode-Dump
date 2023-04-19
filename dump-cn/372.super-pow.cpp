class Solution {
public:
	int superPow(int a, vector<int>& b) {
		int result = 1;
		a %= 1337;
		for (int i = b.size() - 1; i >= 0; --i) {
			result = result % 1337 * myPow(a, b[i]) % 1337;
			a = myPow(a, 10) % 1337;
		}
		return result;
	}

	int myPow(int x, int n) {
		int res = 1;
		for (int i = n; i != 0; i /= 2) {
			if (i % 2 != 0)
				res = res % 1337 * x % 1337;
			x = x % 1337 * x % 1337;
		}
		return res;
	}
};