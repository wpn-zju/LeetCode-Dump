static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		queue<pair<int, int>> myQueue;
		queue<int> disQueue;
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				if (!matrix[i][j]) {
					myQueue.push({ i,j });
					disQueue.push(0);
				}
				else
					matrix[i][j] = INT_MAX;
			}
		}

		while (!myQueue.empty()) {
			pair<int, int>& cur = myQueue.front();
			int& dis = disQueue.front();
			if (dis <= matrix[cur.first][cur.second]) {
				matrix[cur.first][cur.second] = dis;
				int i = cur.first;
				int j = cur.second;
				if (i != 0 && matrix[i - 1][j] == INT_MAX) {
					myQueue.push({ i - 1,j });
					disQueue.push(dis + 1);
				}
				if (i != matrix.size() - 1 && matrix[i + 1][j] == INT_MAX) {
					myQueue.push({ i + 1,j });
					disQueue.push(dis + 1);
				}
				if (j != 0 && matrix[i][j - 1] == INT_MAX) {
					myQueue.push({ i,j - 1 });
					disQueue.push(dis + 1);
				}
				if (j != matrix[0].size() - 1 && matrix[i][j + 1] == INT_MAX) {
					myQueue.push({ i,j + 1 });
					disQueue.push(dis + 1);
				}
			}
			myQueue.pop();
			disQueue.pop();
		}

		return matrix;
	}
};