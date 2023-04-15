class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
		vector<unordered_set<int>> rMap;
		for (int j = 0; j < B[0].size(); ++j) {
			unordered_set<int> mySet;
			for (int i = 0; i < B.size(); ++i)
				if (B[i][j])
					mySet.insert(i);
			rMap.push_back(mySet);
		}
		for (int i = 0; i < result.size(); ++i) {
			for (int j = 0; j < result[0].size(); ++j) {
				int sum = 0;
				for (int k = 0; k < A[0].size(); ++k)
					if (rMap[j].count(k))
						sum += A[i][k] * B[k][j];
				result[i][j] = sum;
			}
		}

		return result;
	}
};