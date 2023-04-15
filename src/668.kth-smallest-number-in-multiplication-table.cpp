static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int start = 1;
		int end = m * n;
		while (start < end) {
			int mid = start + (end - start >> 1);
			int sum = 0;
			int sum2 = 0;
			for (int i = 1; i <= m; ++i) {
				sum += min(n, mid / i);
				sum2 += min(n, (mid - 1) / i);
			}
			if (sum2 < k && sum >= k)
				return mid;
			else if (sum < k)
				start = mid + 1;
			else
				end = mid;
		}
		return start;
	}
};