class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int m = primes.size();
		vector<int> arr(m, 0);
		vector<int> ugly(n, 1);
		for (int i = 1; i < n; ++i) {
			int min = INT_MAX;
			for (int j = 0; j < m; ++j)
				if (min > ugly[arr[j]] * primes[j])
					min = ugly[arr[j]] * primes[j];
			for (int j = 0; j < m; ++j)
				if (min == ugly[arr[j]] * primes[j])
					arr[j]++;
			ugly[i] = min;
		}
		return ugly[n - 1];
	}
};