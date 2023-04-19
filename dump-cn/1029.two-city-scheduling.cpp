class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {return abs(a[0] - a[1]) > abs(b[0] - b[1]); });
		int cost = 0;
		int countA = 0;
		int countB = 0;
		for (vector<int>& vec : costs) {
			if (vec[0] == vec[1])
				cost += vec[0];
			else if (vec[0] < vec[1]) {
				if (countA < costs.size() / 2) {
					cost += vec[0];
					++countA;
				}
				else {
					cost += vec[1];
					++countB;
				}
			}
			else {
				if (countB < costs.size() / 2) {
					cost += vec[1];
					++countB;
				}
				else {
					cost += vec[0];
					++countA;
				}
			}
		}
		return cost;
	}
};