class Solution {
public:
	bool checkBoard(vector<vector<int>>& board, vector<int>& m1, vector<int>& m2) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board.size(); ++j) {
				if (i != 0 && board[m2[i - 1]][m1[j]] == board[m2[i]][m1[j]])
					return false;
				if (i != board.size() - 1 && board[m2[i + 1]][m1[j]] == board[m2[i]][m1[j]])
					return false;
				if (j != 0 && board[m2[i]][m1[j - 1]] == board[m2[i]][m1[j]])
					return false;
				if (j != board.size() - 1 && board[m2[i]][m1[j + 1]] == board[m2[i]][m1[j]])
					return false;
			}
		}
		return true;
	}

	int findMTCB(vector<vector<int>>& board, vector<int>& m1, vector<int>& m2, int start, bool first, bool val) {
		if (first) {
			for (int i = start; i < board.size(); i += 2) {
				if (board[m2[0]][m1[i]] == val)
					return i;
			}
		}
		else {
			for (int i = start; i < board.size(); i += 2) {
				if (board[m2[i]][m1[0]] == val)
					return i;
			}
		}
		return -1;
	}

	int movesToChessboard(vector<vector<int>>& board) {
		int count = 0;
		vector<int> m1(board.size());
		vector<int> m2(board.size());
		for (int i = 0; i < board.size(); ++i)
			m1[i] = m2[i] = i;
		if (board.size() & 1) {
			int count1 = 0, count2 = 0;
			for (int i = 0; i < board.size(); ++i)
				count1 += board[0][i] == 1;
			if (count1 == board.size() / 2) {
				for (int i = 0; i < board.size(); ++i) {
					if (board[0][m1[i]] != (i & 1)) {
						int f = findMTCB(board, m1, m2, i + 1, true, i & 1);
						if (f == -1)
							return -1;
						swap(m1[i], m1[f]);
						++count;
					}
				}
			}
			else if (count1 == board.size() / 2 + 1) {
				for (int i = 0; i < board.size(); ++i) {
					if (board[0][m1[i]] == (i & 1)) {
						int f = findMTCB(board, m1, m2, i + 1, true, !(i & 1));
						if (f == -1)
							return -1;
						swap(m1[i], m1[f]);
						++count;
					}
				}
			}
			else
				return -1;
			for (int i = 0; i < board.size(); ++i)
				count2 += board[i][m1[0]] == 1;
			if (count2 == board.size() / 2) {
				for (int i = 0; i < board.size(); ++i) {
					if (board[m2[i]][m1[0]] != (i & 1)) {
						int f = findMTCB(board, m1, m2, i + 1, false, i & 1);
						if (f == -1)
							return -1;
						swap(m2[i], m2[f]);
						++count;
					}
				}
			}
			else if (count2 == board.size() / 2 + 1) {
				for (int i = 0; i < board.size(); ++i) {
					if (board[m2[i]][m1[0]] == (i & 1)) {
						int f = findMTCB(board, m1, m2, i + 1, false, !(i & 1));
						if (f == -1)
							return -1;
						swap(m2[i], m2[f]);
						++count;
					}
				}
			}
			else
				return -1;
		}
		else {
			int tmp0 = 0, tmp1 = 0;
			for (int i = 0; i < board.size(); i += 2)
				if (board[0][i] == 0)
					++tmp0;
				else
					++tmp1;
			int target = tmp0 > tmp1;
			for (int i = 0; i < board.size(); ++i) {
				if (board[0][m1[i]] == ((i ^ target) & 1)) {
					int f = findMTCB(board, m1, m2, i + 1, true, !board[0][m1[i]]);
					if (f == -1)
						return -1;
					swap(m1[i], m1[f]);
					++count;
				}
			}

			tmp0 = 0, tmp1 = 0;
			for (int i = 0; i < board.size(); i += 2)
				if (board[i][m1[0]] == 0)
					++tmp0;
				else
					++tmp1;
			target = tmp0 > tmp1;
			for (int i = 0; i < board.size(); ++i) {
				if (board[m2[i]][m1[0]] == ((i ^ target) & 1)) {
					int f = findMTCB(board, m1, m2, i + 1, false, !board[m2[i]][m1[0]]);
					if (f == -1)
						return -1;
					swap(m2[i], m2[f]);
					++count;
				}
			}
		}
		return checkBoard(board, m1, m2) ? count : -1;
	}
};