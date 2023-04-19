static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int count = 0;
		sort(g.begin(), g.end(), greater<int>());
		sort(s.begin(), s.end(), greater<int>());
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 < g.size() && ptr2 < s.size()) {
			if (g[ptr1] <= s[ptr2]) {
				++ptr2;
				++count;
			}
			++ptr1;
		}
		return count;
	}
};