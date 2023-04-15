class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> temp(n, string(n, '.'));
		vector<int> queens;
		dfsQueen(result, temp, queens, 0);
		return result;
	}

	bool checkQueen(vector<int>& queens, int row) {
		for (int i = 0; i < queens.size(); ++i)
			if (queens[i] == row || i + queens[i] == row + queens.size() || i - queens[i] == queens.size() - row)
				return false;
		return true;
	}

	void dfsQueen(vector<vector<string>>& result, vector<string>& cur, vector<int>& queens, int column) {
		if (column == cur.size()) {
			result.push_back(cur);
			return;
		}
		for (int i = 0; i < cur.size(); ++i) {
			if (checkQueen(queens, i)) {
				cur[column][i] = 'Q';
				queens.push_back(i);
				dfsQueen(result, cur, queens, column + 1);
				queens.pop_back();
				cur[column][i] = '.';
			}
		}
	}
};