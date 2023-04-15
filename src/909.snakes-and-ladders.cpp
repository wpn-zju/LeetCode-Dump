class Solution {
public:
	int snakesAndLadders(vector<vector<int>>& board) {
		int t = board.size() * board[0].size();
		reverse(board.begin(), board.end());
		vector<int> snakes(t + 1);
		for (int i = 0; i < board.size(); ++i) {
			if (i & 1)
				for (int j = 0; j < board[0].size(); ++j)
					snakes[(i + 1) * board[0].size() - j] = board[i][j];
			else
				for (int j = 0; j < board[0].size(); ++j)
					snakes[i * board[0].size() + j + 1] = board[i][j];
		}
		vector<bool> visited(t + 1, false);
		visited[1] = true;
		queue<int> que;
		que.push(1);
		int count = 0;
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				int cur = que.front();
				if (cur == t)
					return count;
				for (int i = 1; i <= min(6, t - cur); ++i) {
					if (!visited[cur + i]) {
						visited[cur + i] = true;
						if (snakes[cur + i] != -1)
							que.push(snakes[cur + i]);
						else
							que.push(cur + i);
					}
				}
				que.pop();
			}
			++count;
		}
		return -1;
	}
};