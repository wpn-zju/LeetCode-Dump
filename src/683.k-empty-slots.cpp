class Solution {
public:
	int kEmptySlots(vector<int>& bulbs, int K) {
		set<int> count{ bulbs[0] };
		for (int i = 1; i < bulbs.size(); ++i) {
			set<int>::iterator it = count.lower_bound(bulbs[i]);
			if (*it - bulbs[i] == K + 1 || bulbs[i] - *--it == K + 1)
				return i + 1;
			count.insert(bulbs[i]);
		}
		return -1;
	}
};