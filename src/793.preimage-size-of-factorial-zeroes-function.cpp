static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int trailingZeroes(int64_t n) {
		int sum = 0;
		while (n) {
			sum += n / 5;
			n /= 5;
		}
		return sum;
	}

	int preimageSizeFZF(int K) {
        if(K < 5)
            return 5;
		int64_t start = 5;
		int64_t end = 5ll * K;
		while (start < end) {
			int64_t mid = (start + end) / 2;
			int test = trailingZeroes(mid);
			if (test < K)
				start = mid + 1;
			else if (test > K)
				end = mid;
			else
				return 5;
		}
		return 0;
	}
};