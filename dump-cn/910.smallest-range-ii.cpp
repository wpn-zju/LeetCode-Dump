static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int smallestRangeII(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		int result = A.back() - A[0];
		int mx = INT_MIN;
		int mn = INT_MAX;
		for (int i = 0; i < A.size() - 1; ++i) {
			mx = max(A.back() - K, A[i] + K);
			mn = min(A[0] + K, A[i + 1] - K);
			result = min(result, mx - mn);
		}
		return result;
	}
};