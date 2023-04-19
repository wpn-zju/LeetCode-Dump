class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int>> neighbors(N);
		for (vector<int>& vec : paths) {
			neighbors[vec[0] - 1].push_back(vec[1] - 1);
			neighbors[vec[1] - 1].push_back(vec[0] - 1);
		}
		vector<int> result(N, -1);
		for (int i = 0; i < N; ++i) {
			vector<bool> used(4, false);
			for (int& i : neighbors[i]) {
				if (result[i] != -1) {
					used[result[i] - 1] = true;
				}
			}
			for (int n = 0; n < used.size(); ++n) {
				if (!used[n]) {
					result[i] = n + 1;
					break;
				}
			}
		}
		return result;
	}
};