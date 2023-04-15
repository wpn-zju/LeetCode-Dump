class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<int> rows(n, 0);
		vector<int> cols(m, 0);
		for (vector<int>& vec : indices) {
			++rows[vec[0]];
			++cols[vec[1]];
		}
		int count = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if ((rows[i] + cols[j]) & 1)
					++count;
		return count;
	}
};