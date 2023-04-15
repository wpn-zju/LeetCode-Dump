class Solution {
public:
		bool isValidSudoku(vector<vector<char>>& board) {
			vector<vector<bool>> dic(27, vector<bool>(9, false));
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					if (board[i][j] != '.') {
						int tmp = board[i][j] - '0';
						if (dic[i][tmp-1] || dic[j + 9][tmp-1] || dic[18 + (i / 3) * 3 + j / 3][tmp-1])
							return false;
						dic[i][tmp - 1] = dic[j + 9][tmp - 1] = dic[18 + (i / 3) * 3 + j / 3][tmp - 1] = true;
					}
				}
			}
			return true;
		}
};