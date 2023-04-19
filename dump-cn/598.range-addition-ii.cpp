class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int x = m;
		int y = n;
		for (vector<int>& vec : ops) {
			if (vec[0] < x)
				x = vec[0];
			if (vec[1] < y)
				y = vec[1];
		}
		return x * y;
	}
};