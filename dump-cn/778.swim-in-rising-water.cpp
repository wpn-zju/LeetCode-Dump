class Solution {
public:
	int swimInWater(vector<vector<int>>& A) {
		vector<vector<int>> search(A.size(), vector<int>(A[0].size(), INT_MAX));
		search[0][0] = A[0][0];
		auto cmp = [](vector<int>& a, vector<int>& b) {
			return a[2] > b[2];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
		que.push({ 0,0,A[0][0] });
		while (!que.empty()) {
			if (search.back().back() != INT_MAX)
				return search.back().back();
			vector<int> cur = que.top();
			if (cur[0] != 0 && search[cur[0] - 1][cur[1]] == INT_MAX && max(cur[2], A[cur[0] - 1][cur[1]]) < search[cur[0] - 1][cur[1]])
				que.push({ cur[0] - 1,cur[1],search[cur[0] - 1][cur[1]] = max(cur[2], A[cur[0] - 1][cur[1]]) });
			if (cur[0] != A.size() - 1 && search[cur[0] + 1][cur[1]] == INT_MAX && max(cur[2], A[cur[0] + 1][cur[1]]) < search[cur[0] + 1][cur[1]])
				que.push({ cur[0] + 1,cur[1],search[cur[0] + 1][cur[1]] = max(cur[2], A[cur[0] + 1][cur[1]]) });
			if (cur[1] != 0 && search[cur[0]][cur[1] - 1] == INT_MAX && max(cur[2], A[cur[0]][cur[1] - 1]) < search[cur[0]][cur[1] - 1])
				que.push({ cur[0],cur[1] - 1,search[cur[0]][cur[1] - 1] = max(cur[2], A[cur[0]][cur[1] - 1]) });
			if (cur[1] != A[0].size() - 1 && search[cur[0]][cur[1] + 1] == INT_MAX && max(cur[2], A[cur[0]][cur[1] + 1]) < search[cur[0]][cur[1] + 1])
				que.push({ cur[0],cur[1] + 1,search[cur[0]][cur[1] + 1] = max(cur[2], A[cur[0]][cur[1] + 1]) });
			que.pop();
		}
		return search.back().back();
	}
};