static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int orangesRotting(vector<vector<int>>& rooms) {
		int result = 0;
		int countT = 0;
		int countL = 0;
		queue<pair<int, int>> myQueue;
		queue<int> lenQueue;
		for (int i = 0; i < rooms.size(); ++i)
			for (int j = 0; j < rooms[0].size(); ++j)
				switch (rooms[i][j])
				{
				case 0:
					rooms[i][j] = -1;
					break;
				case 1:
					rooms[i][j] = INT_MAX;
					countT++;
					break;
				case 2:
					rooms[i][j] = INT_MAX;
					countT++;
					myQueue.push({ i,j });
					lenQueue.push(0);
					break;
				}
		while (!myQueue.empty()) {
			int curLen = lenQueue.front();
			pair<int, int> cur = myQueue.front();
			if (rooms[cur.first][cur.second] == INT_MAX) {
				countL++;
				result = max(curLen, result);
				rooms[cur.first][cur.second] = curLen;
				if (cur.first != 0 && rooms[cur.first - 1][cur.second] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first - 1, cur.second });
					lenQueue.push(curLen + 1);
				}
				if (cur.first != rooms.size() - 1 && rooms[cur.first + 1][cur.second] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first + 1, cur.second });
					lenQueue.push(curLen + 1);
				}
				if (cur.second != 0 && rooms[cur.first][cur.second - 1] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first, cur.second - 1 });
					lenQueue.push(curLen + 1);
				}
				if (cur.second != rooms[0].size() - 1 && rooms[cur.first][cur.second + 1] > rooms[cur.first][cur.second]) {
					myQueue.push({ cur.first, cur.second + 1 });
					lenQueue.push(curLen + 1);
				}
			}
			myQueue.pop();
			lenQueue.pop();
		}
		return countL == countT ? result : -1;
	}
};