class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		queue<pair<int, int>> myQueue;
		queue<int> lenQueue;
		for (int i = 0; i < rooms.size(); ++i)
			for (int j = 0; j < rooms[0].size(); ++j)
				if (!rooms[i][j]) {
					myQueue.push({ i,j });
					lenQueue.push(0);
				}
		while (!myQueue.empty()) {
			int curLen = lenQueue.front();
			pair<int, int> cur = myQueue.front();
			rooms[cur.first][cur.second] = min(rooms[cur.first][cur.second], curLen);
			if (cur.first != 0) {
				if (rooms[cur.first - 1][cur.second] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first - 1, cur.second });
					lenQueue.push(curLen + 1);
				}
			}
			if (cur.first != rooms.size() - 1) {
				if (rooms[cur.first + 1][cur.second] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first + 1, cur.second });
					lenQueue.push(curLen + 1);
				}
			}
			if (cur.second != 0) {
				if (rooms[cur.first][cur.second - 1] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first, cur.second - 1 });
					lenQueue.push(curLen + 1);
				}
			}
			if (cur.second != rooms[0].size() - 1) {
				if (rooms[cur.first][cur.second + 1] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first, cur.second + 1 });
					lenQueue.push(curLen + 1);
				}
			}
			myQueue.pop();
			lenQueue.pop();
		}
	}
};