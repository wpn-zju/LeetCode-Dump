class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		pair<int, int> rook;
		for(int i =0;i<8;++i)
			for(int j =0;j<8;++j)
				if (board[i][j] == 'R')
					rook = { i,j };
		int result = 0;
		for (int i = rook.first - 1; i >= 0; --i) {
			if (board[i][rook.second] == 'B')
				break;
			else if (board[i][rook.second] == 'p') {
				++result;
				break;
			}
		}
		for (int i = rook.first + 1; i < 8; ++i) {
			if (board[i][rook.second] == 'B')
				break;
			else if (board[i][rook.second] == 'p') {
				++result;
				break;
			}
		}
		for (int i = rook.second - 1; i >= 0; --i) {
			if (board[rook.first][i] == 'B')
				break;
			else if (board[rook.first][i] == 'p') {
				++result;
				break;
			}
		}
		for (int i = rook.second + 1; i < 8; ++i) {
			if (board[rook.first][i] == 'B')
				break;
			else if (board[rook.first][i] == 'p') {
				++result;
				break;
			}
		}
		return result;
	}
};