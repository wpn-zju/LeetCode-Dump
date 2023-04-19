class Solution {
public:
	bool checkQueen(vector<int>& queens, int row) {
		for (int i = 0; i < queens.size(); ++i)
			if (queens[i] == row || i + queens[i] == row + queens.size() || i - queens[i] == queens.size() - row)
				return false;
		return true;
	}

	int totalNQueens(int n) {
		int result = 0;
		vector<string> temp(n, string(n, '.'));
		vector<int> queens;
		dfsQueenN(result, temp, queens, 0);
		return result;
	}

	void dfsQueenN(int& result, vector<string>& cur, vector<int>& queens, int column) {
		if (column == cur.size()) {
			result++;
			return;
		}
		for (int i = 0; i < cur.size(); ++i) {
			if (checkQueen(queens, i)) {
				cur[column][i] = 'Q';
				queens.push_back(i);
				dfsQueenN(result, cur, queens, column + 1);
				queens.pop_back();
				cur[column][i] = '.';
			}
		}
	}
};