static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int count = 0;
		for (int i = 0; i < A[0].size(); ++i)
			for (int j = 0; j < A.size() - 1; ++j)
				if (A[j + 1][i] < A[j][i]) {
					count++;
					break;
				}
		return count;
	}
};