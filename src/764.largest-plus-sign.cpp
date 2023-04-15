class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
		vector<vector<int>> data(N, vector<int>(N, N));
		for (vector<int>& vec : mines)
			data[vec[0]][vec[1]] = 0;
		for (int k = 0; k < N; ++k) {
			int l = 0, r = 0, u = 0, d = 0;
			for (int i = 0, j = N - 1; i < N; ++i, --j) {
				l = data[k][i] == 0 ? 0 : l + 1;
				data[k][i] = min(data[k][i], l);
				r = data[k][j] == 0 ? 0 : r + 1;
				data[k][j] = min(data[k][j], r);
				u = data[i][k] == 0 ? 0 : u + 1;
				data[i][k] = min(data[i][k], u);
				d = data[j][k] == 0 ? 0 : d + 1;
				data[j][k] = min(data[j][k], d);
			}
		}
		int result = 0;
		for (vector<int>& vec : data)
			for (int& i : vec)
				result = max(i, result);
		return result;
	}
};