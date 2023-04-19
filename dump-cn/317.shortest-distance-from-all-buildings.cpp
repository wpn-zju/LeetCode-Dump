static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int shortestDistance(vector<vector<int>>& grid) {
		int buildings = 0;
		int result = INT_MAX;
		vector<vector<int>> disStore(grid.size(), vector<int>(grid[0].size(), 0));
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					result = INT_MAX;
					vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
					queue<pair<int, int>> myQueue;
					myQueue.push({ i,j });
					while (!myQueue.empty()) {
						pair<int, int>& p = myQueue.front();
						int& x = p.first;
						int& y = p.second;
						if (x != 0 && grid[x - 1][y] == buildings) {
							--grid[x - 1][y]; 
							myQueue.push({ x - 1,y });
							visited[x - 1][y] = visited[x][y] + 1;
							disStore[x - 1][y] += visited[x - 1][y];
							result = min(result, disStore[x - 1][y]);
						}
						if (x != grid.size() - 1 && grid[x + 1][y] == buildings) {
							--grid[x + 1][y];
							myQueue.push({ x + 1,y });
							visited[x + 1][y] = visited[x][y] + 1;
							disStore[x + 1][y] += visited[x + 1][y];
							result = min(result, disStore[x + 1][y]);
						}
						if (y != 0 && grid[x][y - 1] == buildings) {
							--grid[x][y - 1];
							myQueue.push({ x,y - 1 });
							visited[x][y - 1] = visited[x][y] + 1;
							disStore[x][y - 1] += visited[x][y - 1];
							result = min(result, disStore[x][y - 1]);
						}
						if (y != grid[0].size() - 1 && grid[x][y + 1] == buildings) {
							--grid[x][y + 1];
							myQueue.push({ x,y + 1 });
							visited[x][y + 1] = visited[x][y] + 1;
							disStore[x][y + 1] += visited[x][y + 1];
							result = min(result, disStore[x][y + 1]);
						}
                        myQueue.pop();
					}
					--buildings;
				}
			}
		}
		return result == INT_MAX ? -1 : result;
	}
};