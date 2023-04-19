class Solution {
public:
	int minKnightMoves(int x, int y) {
		vector<pair<int, int>> dir{ {1,2},{2,1},{-1,-2},{-2,-1},{1,-2},{-2,1},{-1,2},{2,-1} };
		unordered_map<int, unordered_map<int, bool>> visited;
		queue<pair<int, int>> que;
		que.push({ 0,0 });
		int count = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				pair<int, int>& cur = que.front();
                if(cur.first == x && cur.second == y)
                    return count;
				for (int i = 0; i < dir.size(); ++i) {
					if (cur.first + dir[i].first >= min(-2, x - 2) && cur.first + dir[i].first <= max(2, x + 2) &&
						cur.second + dir[i].second >= min(-2, y - 2) && cur.second + dir[i].second <= max(2, y + 2) && !visited[cur.first + dir[i].first][cur.second + dir[i].second]) {
						visited[cur.first + dir[i].first][cur.second + dir[i].second] = true;
						que.push({ cur.first + dir[i].first,cur.second + dir[i].second });
					}
				}
				que.pop();
			}
			++count;
		}
		return -1;
	}
};