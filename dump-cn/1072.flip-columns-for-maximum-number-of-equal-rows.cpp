static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		int result = 0;
		vector<string> strVec;
		for (int i = 0; i < matrix.size(); ++i)
			if (matrix[i][0])
				for (int j = 0; j < matrix[0].size(); ++j)
					matrix[i][j] = !matrix[i][j];
		for (int i = 0; i < matrix.size() - 1; ++i) {
			int count = 1;
			for (int j = i + 1; j < matrix.size(); ++j)
				if (matrix[i] == matrix[j])
					count++;
			result = max(result, count);
		}
		return result;
	}
};