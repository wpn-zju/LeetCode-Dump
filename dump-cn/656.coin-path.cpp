class Solution {
public:
	vector<int> cheapestJump(vector<int>& A, int B) {
		if (A.back() == -1)
			return {};
		vector<int> result;
		vector<int> dp(A.size(), 100000000);
		vector<int> path(A.size(), 100000000);
		dp.back() = A.back();
		path.back() = -1;
		for (int i = A.size() - 2; i >= 0; --i) {
			if (A[i] != -1) {
				int t = min(i + B, (int)A.size() - 1);
				for (int j = t; j > i; --j) {
					if (dp[i] >= dp[j] + A[i]) {
						dp[i] = dp[j] + A[i];
						path[i] = j;
					}
				}
			}
		}
		if (dp[0] == 100000000)
			return {};
		int cur = 0;
		while (cur >= 0) {
			result.push_back(cur + 1);
			cur = path[cur];
		}
		return result;
	}
};