class Solution {
public:
	bool exist(vector<vector<char>>& board, string& word) {
		if (word.empty())
			return true;
		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				if (board[i][j] == word.front()) {
					vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
					if (dfs(board, i, j, word, 1, visited))
						return true;
				}
		return false;
	}

	bool dfs(vector<vector<char>>& board, int x, int y, string& word, int index, vector<vector<bool>>& visited) {
		if (index == word.length())
			return true;
		visited[x][y] = true;
		if (x != 0 && !visited[x - 1][y] && board[x - 1][y] == word[index] && dfs(board, x - 1, y, word, index + 1, visited))
			return true;
		if (x != board.size() - 1 && !visited[x + 1][y] && board[x + 1][y] == word[index] && dfs(board, x + 1, y, word, index + 1, visited))
			return true;
		if (y != 0 && !visited[x][y - 1] && board[x][y - 1] == word[index] && dfs(board, x, y - 1, word, index + 1, visited))
			return true;
		if (y != board[0].size() - 1 && !visited[x][y + 1] && board[x][y + 1] == word[index] && dfs(board, x, y + 1, word, index + 1, visited))
			return true;
		return visited[x][y] = false;
	}
};