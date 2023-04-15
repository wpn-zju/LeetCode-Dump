class Solution {
public:
	vector<int> pourWater(vector<int>& heights, int V, int K) {
		for (int i = 0; i < V; ++i) {
			int mn = INT_MAX;
			int mnI = 0;
			for (int n = K - 1; n >= 0; --n) {
				if (heights[n] > heights[n + 1])
					break;
				if (heights[n] < mn) {
					mn = heights[n];
					mnI = n;
				}
			}
			if (mn < heights[K]) {
				heights[mnI]++;
			}
			else {
				for (int n = K + 1; n < heights.size(); ++n) {
					if (heights[n] > heights[n - 1])
						break;
					if (heights[n] < mn) {
						mn = heights[n];
						mnI = n;
					}
				}
				if (mn < heights[K]) {
					heights[mnI]++;
				}
				else {
					heights[K]++;
				}
			}
		}
		return heights;
	}
};