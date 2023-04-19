class Solution {
public:
	int smallestFactorization(int a) {
		if (a == 1)
			return 1;
		vector<int> count(8, 0);
		for (int i = 9; i >= 2; --i) {
			while (a % i == 0) {
				++count[i - 2];
				a /= i;
			}
		}
		if (a > 1)
			return 0;
		int result = 0;
		for (int i = 0; i < count.size(); ++i) {
			for (int j = 0; j < count[i]; ++j) {
				if (result > INT_MAX / 10)
					return 0;
				result *= 10;
				result += i + 2;
			}
		}
		return result;
	}
};