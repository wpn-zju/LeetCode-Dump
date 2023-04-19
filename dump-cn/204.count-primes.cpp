class Solution {
public:
	int countPrimes(int n) {
		vector<bool> tmp(max(2, n), true);
		tmp[0] = tmp[1] = false;
		int t = sqrt(n);
		for (int i = 2; i <= t; ++i) {
			if (tmp[i]) {
				for (int x = i * i; x < n; x += i) {
					tmp[x] = false;
				}
			}
		}
		int count = 0;
		for (int i = 0; i < n; ++i)
			count += tmp[i];
		return count;
	}
};