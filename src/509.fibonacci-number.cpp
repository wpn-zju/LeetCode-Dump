class Solution {
public:
	int fib(int N) {
		if (!N) return N;
		int a = 0;
		int b = 1;
		for (int i = 1; i < N; ++i) {
			a += b;
			swap(a, b);
		}
		return b;
	}
};