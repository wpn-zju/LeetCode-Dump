class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		vector<int> vecA(8, 0);
		vector<int> vecB(8, 0);
		int countO = 0;
		int countX = 0;
		for (int i = 0;i<3;++i)
			for (int j = 0;j<3;++j)
				if (board[i][j] == 'O') {
					vecA[i]++;
					vecA[j + 3]++;
					if (i == j)
						vecA[6]++;
					if (i + j == 2)
						vecA[7]++;
					countO++;
				}
				else if (board[i][j] == 'X') {
					vecB[i]++;
					vecB[j + 3]++;
					if (i == j)
						vecB[6]++;
					if (i + j == 2)
						vecB[7]++;
					countX++;
				}
		bool winA = false, winB = false;
		for (int i : vecA)
			if (i == 3)
				winA = true;
		for (int i : vecB)
			if (i == 3)
				winB = true;
		if (winA && winB)
			return false;
		else if (winA)
			return countO == countX;
		else if (winB)
			return countO == countX - 1;
		else
			return countO == countX - 1 || countO == countX;
	}
};