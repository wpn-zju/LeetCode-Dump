class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
			return board;
		}
		vector<vector<int>> tmp = { {-1,-1},{-1,0}, {-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1} };
		vector<bool> visited(board.size()*board[0].size(), false);
		vector<vector<int>> bombCount(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				for (int k = 0; k < tmp.size(); ++k)
					if (i + tmp[k][0] >= 0 && i + tmp[k][0] < board.size() && j + tmp[k][1] >= 0 && j + tmp[k][1] < board[0].size())
						if (board[i + tmp[k][0]][j + tmp[k][1]] == 'M')
							bombCount[i][j]++;
		dfs(board, visited, bombCount, click[0], click[1]);
		return board;
	}

	void dfs(vector<vector<char>>& board, vector<bool>& visited, vector<vector<int>>& bCount, int x, int y) {
		if (visited[x*board[0].size() + y])
			return;
		visited[x*board[0].size() + y] = true;
		if (board[x][y] == 'M')
			return;
		if (bCount[x][y]) {
			board[x][y] = bCount[x][y] + '0';
			return;
		}
		board[x][y] = 'B';
		if (x != 0)
			dfs(board, visited, bCount, x - 1, y);
		if (x != board.size() - 1)
			dfs(board, visited, bCount, x + 1, y);
		if (y != 0)
			dfs(board, visited, bCount, x, y - 1);
		if (y != board[0].size() - 1)
			dfs(board, visited, bCount, x, y + 1);
		if (x != 0 && y != 0)
			dfs(board, visited, bCount, x - 1, y - 1);
		if (x != 0 && y != board[0].size() - 1)
			dfs(board, visited, bCount, x - 1, y + 1);
		if (x != board.size() - 1 && y != 0)
			dfs(board, visited, bCount, x + 1, y - 1);
		if (x != board.size() - 1 && y != board[0].size() - 1)
			dfs(board, visited, bCount, x + 1, y + 1);
	}
};