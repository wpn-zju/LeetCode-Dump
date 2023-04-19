class Solution {
public:
	int longestLine(vector<vector<int>>& M) {
		if (M.empty())
			return 0;
		int m = M.size();
		int n = M[0].size();
		int result = 0;
		for (int i = 0; i < m; ++i) {
			int count = 0;
			int cur = 0;
			for (int j = 0; j < n; ++j) {
				if (M[i][j] == 1) {
					++cur;
					count = max(count, cur);
				}
				else {
					cur = 0;
				}
			}
			result = max(result, count);
		}
		for (int i = 0; i < n; ++i) {
			int count = 0;
			int cur = 0;
			for (int j = 0; j < m; ++j) {
				if (M[j][i] == 1) {
					++cur;
					count = max(count, cur);
				}
				else {
					cur = 0;
				}
			}
			result = max(result, count);
		}
		for (int i = 0; i < m + n - 1; ++i) {
			int count = 0;
			int cur = 0;
			for (int j = max(0, i - n + 1); j <= min(m - 1, i); ++j) {
				if (M[j][i - j] == 1) {
					++cur;
					count = max(count, cur);
				}
				else {
					cur = 0;
				}
			}
			result = max(result, count);
		}
		for (int i = 1 - n; i < m; ++i) {
			int count = 0;
			int cur = 0;
			for (int j = max(0, i); j <= min(m - 1, i + n - 1); ++j) {
				if (M[j][j - i] == 1) {
					++cur;
					count = max(count, cur);
				}
				else {
					cur = 0;
				}
			}
			result = max(result, count);
		}
		return result;
	}
};