class Solution {
public:
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		if (!N)
			return cells;
		int n = N % 14;
		if (!n)
			n = 14;
		while (n--) {
			vector<int> tmp = vector<int>(cells);
			for (int i = 1; i < 7; ++i)
				cells[i] = (tmp[i - 1] ^ !tmp[i + 1]);
			cells[0] = cells[7] = 0;
		}
		return cells;
	}
};