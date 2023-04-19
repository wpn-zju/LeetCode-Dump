static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		vector<bool> store(matrix.size() + matrix[0].size(), true);
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[i].size(); ++j)
				if (!matrix[i][j])
					store[i] = store[matrix.size() + j] = false;
		for (int i = 0; i < matrix.size(); ++i)
			for (int j = 0; j < matrix[0].size(); ++j)
				if (!store[i] || !store[matrix.size() + j])
					matrix[i][j] = 0;
	}
};