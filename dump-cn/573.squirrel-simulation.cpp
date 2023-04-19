class Solution {
public:
	int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
		int result = INT_MAX;
		int sum = 0;
		for (int i = 0; i < nuts.size(); ++i)
			sum += 2 * (abs(tree[0] - nuts[i][0]) + abs(tree[1] - nuts[i][1]));
		for (int i = 0; i < nuts.size(); ++i)
			result = min(result, sum - abs(tree[0] - nuts[i][0]) - abs(tree[1] - nuts[i][1]) + abs(squirrel[0] - nuts[i][0]) + abs(squirrel[1] - nuts[i][1]));
		return result;
	}
};