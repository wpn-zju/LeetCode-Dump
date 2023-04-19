static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int arrangeCoins(int n) {
		return (sqrt(1 + 8ll * n) - 1) / 2;
	}
};