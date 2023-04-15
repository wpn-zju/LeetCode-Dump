class TicTacToe {
public:
	int n;
	vector<int> reAVec;
	vector<int> reBVec;

	TicTacToe(int n) {
		this->n = n;
		reAVec = vector<int>(2 * n + 2, 0);
		reBVec = vector<int>(2 * n + 2, 0);
	}

	int move(int row, int col, int player) {
		return player * (player == 1 ? ++reAVec[row] == n | ++reAVec[n + col] == n | ((row == col) && (++reAVec[2 * n] == n)) | ((row + col + 1 == n) && (++reAVec[2 * n + 1] == n)) : ++reBVec[row] == n | ++reBVec[n + col] == n | ((row == col) && (++reBVec[2 * n] == n)) | ((row + col + 1 == n) && (++reBVec[2 * n + 1] == n)));
	}
};