class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		vector<vector<int>> result(2, vector<int>(colsum.size(), 0));
		for (int i = 0; i < colsum.size(); ++i) {
			if (colsum[i] == 2) {
				result[0][i] = result[1][i] = 1;
				--upper;
				--lower;
			}
		}
		for (int i = 0; i < colsum.size(); ++i) {
			if (colsum[i] == 1) {
				if (upper > lower) {
					--upper;
					result[0][i] = 1;
				}
				else {
					--lower;
					result[1][i] = 1;
				}
			}
		}
		return !lower && !upper ? result : vector<vector<int>>();
	}
};