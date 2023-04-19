class Solution {
public:
	vector<int>* dp;
	int getBiggestFactor(int& n) {
		for (int i = n >> 1; i; --i)
			if (n % i == 0)
				return i;
		return 0;
	}

	int minSteps2(int& n) {
		if ((*dp)[n] != -1)
			return (*dp)[n];
		int tmp = getBiggestFactor(n);
		if (tmp == 1)
			return (*dp)[n] = n;
		else
			return (*dp)[n] = minSteps2(tmp) + n / tmp;
	}

	int minSteps(int& n) {
		dp = new vector<int>(n + 1, -1);
		(*dp)[1] = 0;
		return minSteps2(n);
	}
};