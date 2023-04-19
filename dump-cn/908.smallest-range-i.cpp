static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int mx = INT_MIN;
        int mn = INT_MAX;
        for(int& i : A){
            mx = max(mx, i);
            mn = min(mn, i);
        }
		return max(0, mx - mn - 2 * K);
	}
};