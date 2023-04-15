class Solution {
public:
	vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
		unordered_map<int, vector<int>> mapB;
		for (int i = 0; i < B.size(); ++i)
			mapB[B[i]].push_back(i);
		vector<int> result(B.size());
		for (int i = 0; i < B.size(); ++i) {
			result[i] = mapB[A[i]][mapB[A[i]].size() - 1];
			mapB[A[i]].pop_back();
		}
		return result;
	}
};