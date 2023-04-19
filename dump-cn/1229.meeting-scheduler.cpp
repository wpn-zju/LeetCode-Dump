static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
		sort(slots1.begin(), slots1.end(), [](vector<int>& a, vector<int>& b) { return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]; });
		sort(slots2.begin(), slots2.end(), [](vector<int>& a, vector<int>& b) { return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]; });
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 < slots1.size() && ptr2 < slots2.size()) {
			vector<int>& vec1 = slots1[ptr1];
			vector<int>& vec2 = slots2[ptr2];
			if (vec1[0] > vec2[1]) {
				++ptr2;
			}
			else if (vec2[0] > vec1[1]) {
				++ptr1;
			}
			else if (vec1[0] > vec2[0]) {
				if (min(vec1[1], vec2[1]) - vec1[0] >= duration)
					return { vec1[0], vec1[0] + duration };
				else {
					if (vec1[1] > vec2[1]) {
						++ptr2;
					}
					else {
						++ptr1;
					}
				}
			}
			else {
				if (min(vec1[1], vec2[1]) - vec2[0] >= duration)
					return { vec2[0], vec2[0] + duration };
				else {
					if (vec1[1] > vec2[1]) {
						++ptr2;
					}
					else {
						++ptr1;
					}
				}
			}
		}
		return {};
	}
};