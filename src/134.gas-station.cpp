static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int ptr = 0;
		int prev = 0;
		int cur = 0;
		int last = 0;
		while (ptr != gas.size()) {
			cur += gas[ptr] - cost[ptr];
			++ptr;
			if (cur < 0) {
				last += cur;
				cur = 0;
				prev = ptr;
			}
		}
		return cur + last < 0 ? -1 : prev;
	}
};