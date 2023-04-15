class Solution {
public:
	int smallestRepunitDivByK(int K) {
		if (K % 2 == 0 || K % 5 == 0)
			return -1;
		int count = 1;
		int t = 1;
		while (t %= K) {
			t = 10 * t + 1;
			++count;
		}
		return count;
	}
};