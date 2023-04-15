class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> cellCount(board.size(), vector<int>(board[0].size(), 0));
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j]) {
					if (i != 0)
						++cellCount[i - 1][j];
					if (i != board.size() - 1)
						++cellCount[i + 1][j];
					if (j != 0)
						++cellCount[i][j - 1];
					if (j != board[0].size() - 1)
						++cellCount[i][j + 1];
					if (i != 0 && j != 0)
						++cellCount[i - 1][j - 1];
					if (i != board.size() - 1 && j != 0)
						++cellCount[i + 1][j - 1];
					if (i != 0 && j != board[0].size() - 1)
						++cellCount[i - 1][j + 1];
					if (i != board.size() - 1 && j != board[0].size() - 1)
						++cellCount[i + 1][j + 1];
				}
			}
		}

		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] && (cellCount[i][j] < 2 || cellCount[i][j] > 3))
					board[i][j] = 0;
				if (!board[i][j] && cellCount[i][j] == 3)
					board[i][j] = 1;
			}
		}
	}
};