class Solution {
public:
	int maximumMinimumPath(vector<vector<int>>& A) {
		vector<vector<int>> search(A.size(), vector<int>(A[0].size(), 0));
		search[0][0] = A[0][0];
		auto cmp = [](vector<int>& a, vector<int>& b) {
			return a[2] < b[2];
		};
		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
		que.push({ 0,0,A[0][0] });
		while (!que.empty()) {
			if (search.back().back())
				return search.back().back();
			if (que.top()[0] != 0 && !search[que.top()[0] - 1][que.top()[1]] && min(que.top()[2], A[que.top()[0] - 1][que.top()[1]]) > search[que.top()[0] - 1][que.top()[1]])
				que.push({ que.top()[0] - 1,que.top()[1],search[que.top()[0] - 1][que.top()[1]] = min(que.top()[2], A[que.top()[0] - 1][que.top()[1]]) });
			if (que.top()[0] != A.size() - 1 && !search[que.top()[0] + 1][que.top()[1]] && min(que.top()[2], A[que.top()[0] + 1][que.top()[1]]) > search[que.top()[0] + 1][que.top()[1]])
				que.push({ que.top()[0] + 1,que.top()[1],search[que.top()[0] + 1][que.top()[1]] = min(que.top()[2], A[que.top()[0] + 1][que.top()[1]]) });
			if (que.top()[1] != 0 && !search[que.top()[0]][que.top()[1] - 1] && min(que.top()[2], A[que.top()[0]][que.top()[1] - 1]) > search[que.top()[0]][que.top()[1] - 1])
				que.push({ que.top()[0],que.top()[1] - 1,search[que.top()[0]][que.top()[1] - 1] = min(que.top()[2], A[que.top()[0]][que.top()[1] - 1]) });
			if (que.top()[1] != A[0].size() - 1 && !search[que.top()[0]][que.top()[1] + 1] && min(que.top()[2], A[que.top()[0]][que.top()[1] + 1]) > search[que.top()[0]][que.top()[1] + 1])
				que.push({ que.top()[0],que.top()[1] + 1,search[que.top()[0]][que.top()[1] + 1] = min(que.top()[2], A[que.top()[0]][que.top()[1] + 1]) });
			que.pop();
		}
		return search.back().back();
	}
};