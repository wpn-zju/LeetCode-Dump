class Solution {
public:
		void solveSudoku(vector<vector<char>>& board) {
			vector<vector<bool>> dic(27, vector<bool>(9, false));
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					if (board[i][j] != '.') {
						int tmp = board[i][j] - '0';
						dic[i][tmp - 1] = dic[j + 9][tmp - 1] = dic[18 + (i / 3) * 3 + j / 3][tmp - 1] = true;
					}
				}
			}
			solveSudoku(board, dic, 0, 0);
		}

		bool solveSudoku(vector<vector<char>>& board, vector<vector<bool>>& dic, int i, int j) {
			while (board[i][j] != '.') {
				j++;
				if (j == 9) {
					j = 0;
					i++;
					if (i == 9)
						return true;
				}
			}
			for (int k = 0; k < 9; ++k) {
				if (dic[i][k] || dic[j + 9][k] || dic[18 + (i / 3) * 3 + j / 3][k])
					continue;
				board[i][j] = k + 1 + '0';
				dic[i][k] = dic[j + 9][k] = dic[18 + (i / 3) * 3 + j / 3][k] = true;
				if (solveSudoku(board, dic, i, j))
					return true;
				board[i][j] = '.';
				dic[i][k] = dic[j + 9][k] = dic[18 + (i / 3) * 3 + j / 3][k] = false;
			}
			return false;
		}
};