class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> indegree(N, 0);
		vector<int> outdegree(N, 0);
		for (vector<int>& vec : trust) {
			++indegree[vec[1] - 1];
			++outdegree[vec[0] - 1];
		}
		for (int i = 0; i < N; ++i)
			if (indegree[i] == N - 1 && outdegree[i] == 0)
				return i + 1;
		return -1;
	}
};