static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	pair<int, int> findOne(vector<vector<int>>& rooms) {
		for (int i = 0; i < rooms.size(); ++i)
			for (int j = 0; j < rooms[0].size(); ++j)
				if (rooms[i][j])
					return{ i,j };
		return { 0,0 };
	}

	// 扩散数
	int shortestBridge(vector<vector<int>>& rooms) {
		queue<pair<int, int>> myQueue2;
		queue<pair<int, int>> myQueue;
		myQueue.push(findOne(rooms));
		while (!myQueue.empty()) {
			pair<int, int> cur = myQueue.front();
			if (rooms[cur.first][cur.second] != 2) {
				rooms[cur.first][cur.second] = 2;
				myQueue2.push(cur);
				if (cur.first != 0)
					if (rooms[cur.first - 1][cur.second] == 1)
						myQueue.push({ cur.first - 1, cur.second });
				if (cur.first != rooms.size() - 1)
					if (rooms[cur.first + 1][cur.second] == 1)
						myQueue.push({ cur.first + 1, cur.second });
				if (cur.second != 0)
					if (rooms[cur.first][cur.second - 1] == 1)
						myQueue.push({ cur.first, cur.second - 1 });
				if (cur.second != rooms[0].size() - 1)
					if (rooms[cur.first][cur.second + 1] == 1)
						myQueue.push({ cur.first, cur.second + 1 });
			}
			myQueue.pop();
		}

		while (!myQueue2.empty()) {
			pair<int, int> cur = myQueue2.front();
			if (cur.first != 0)
				if (rooms[cur.first - 1][cur.second] == 1)
					return rooms[cur.first][cur.second] - 2;
				else if (rooms[cur.first - 1][cur.second] == 0) {
					rooms[cur.first - 1][cur.second] = rooms[cur.first][cur.second] + 1;
					myQueue2.push({ cur.first - 1, cur.second });
				}
			if (cur.first != rooms.size() - 1)
				if (rooms[cur.first + 1][cur.second] == 1)
					return rooms[cur.first][cur.second] - 2;
				else if (rooms[cur.first + 1][cur.second] == 0) {
					rooms[cur.first + 1][cur.second] = rooms[cur.first][cur.second] + 1;
					myQueue2.push({ cur.first + 1, cur.second });
				}
			if (cur.second != 0)
				if (rooms[cur.first][cur.second - 1] == 1)
					return rooms[cur.first][cur.second] - 2;
				else if (rooms[cur.first][cur.second - 1] == 0) {
					rooms[cur.first][cur.second - 1] = rooms[cur.first][cur.second] + 1;
					myQueue2.push({ cur.first, cur.second - 1 });
				}
			if (cur.second != rooms[0].size() - 1)
				if (rooms[cur.first][cur.second + 1] == 1)
					return rooms[cur.first][cur.second] - 2;
				else if (rooms[cur.first][cur.second + 1] == 0) {
					rooms[cur.first][cur.second + 1] = rooms[cur.first][cur.second] + 1;
					myQueue2.push({ cur.first, cur.second + 1 });
				}
			myQueue2.pop();
		}
		return 0;
	}
};