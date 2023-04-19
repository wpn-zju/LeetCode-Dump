class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		vector<vector<bool>> queen(8, vector<bool>(8, false));
		vector<vector<int>> result;
		for (vector<int>& vec : queens)
			queen[vec[0]][vec[1]] = true;
		for (int i = king[0] - 1; i >= 0; --i) {
			if (queen[i][king[1]]) {
				result.push_back({ i,king[1] });
				break;
			}
		}
		for (int i = king[0] + 1; i <= 7; ++i) {
			if (queen[i][king[1]]) {
				result.push_back({ i,king[1] });
				break;
			}
		}
		for (int i = king[1] - 1; i >= 0; --i) {
			if (queen[king[0]][i]) {
				result.push_back({ king[0],i });
				break;
			}
		}
		for (int i = king[1] + 1; i <= 7; ++i) {
			if (queen[king[0]][i]) {
				result.push_back({ king[0],i });
				break;
			}
		}
		for (int i = 1; i <= min(king[0], king[1]); ++i) {
			if (queen[king[0] - i][king[1] - i]) {
				result.push_back({ king[0] - i,king[1] - i });
				break;
			}
		}
		for (int i = 1; i <= min(king[0], 7 - king[1]); ++i) {
			if (queen[king[0] - i][king[1] + i]) {
				result.push_back({ king[0] - i,king[1] + i });
				break;
			}
		}
		for (int i = 1; i <= min(7 - king[0], king[1]); ++i) {
			if (queen[king[0] + i][king[1] - i]) {
				result.push_back({ king[0] + i,king[1] - i });
				break;
			}
		}
		for (int i = 1; i <= min(7 - king[0], 7 - king[1]); ++i) {
			if (queen[king[0] + i][king[1] + i]) {
				result.push_back({ king[0] + i,king[1] + i });
				break;
			}
		}
		return result;
	}
};