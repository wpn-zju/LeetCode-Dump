class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		for (int i = 0; i + 3 < x.size(); ++i) {
			if (x[i + 2] <= x[i] && x[i + 1] <= x[i + 3])
				return true;
			if (i + 4 < x.size() && x[i + 1] == x[i + 3] && x[i + 4] >= x[i + 2] - x[i])
				return true;
			if (i + 5 < x.size() && x[i + 1] <= x[i + 3] && x[i + 4] <= x[i + 2] && x[i + 4] >= x[i + 2] - x[i] && x[i + 5] >= x[i + 3] - x[i + 1])
				return true;
		}
		return false;
	}
};