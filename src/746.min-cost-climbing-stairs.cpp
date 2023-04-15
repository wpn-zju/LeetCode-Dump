class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
	cost.push_back(0);
	int s1 = 0;
	int s2 = min(cost[0], cost[1]);
	for (int i = 2; i < cost.size(); ++i) {
		int s3 = min(s2 + cost[i], s1 + cost[i - 1]);
		s1 = s2;
		s2 = s3;
	}
	return s2;
}
};