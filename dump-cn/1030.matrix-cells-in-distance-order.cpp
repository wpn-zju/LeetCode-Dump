class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> dis(R, vector<int>(C));
		vector<vector<int>> result(R * C, vector<int>(2));
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				dis[i][j] = abs(i - r0) + abs(j - c0);
				result[i * C + j] = { i,j };
			}
		}
		sort(result.begin(), result.end(), [&dis](vector<int>& a, vector<int>& b) {
			return dis[a[0]][a[1]] < dis[b[0]][b[1]];
		});
		return result;
	}
};