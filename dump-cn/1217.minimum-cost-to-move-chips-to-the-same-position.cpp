class Solution {
public:
	int minCostToMoveChips(vector<int>& chips) {
		int count = 0;
		for (int& i : chips)
			if (i %= 2)
				++count;
		return min(count, (int)chips.size() - count);
	}
};