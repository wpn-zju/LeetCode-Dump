static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int partitionDisjoint(vector<int>& A) {
		vector<int> dpMax(A.size(), INT_MAX);
		vector<int> dpMin(A.size(), INT_MIN);
		dpMax[0] = A[0];
		dpMin[A.size() - 1] = A.back();
		for (int i = 1; i < A.size(); ++i)
			dpMax[i] = max(A[i], dpMax[i - 1]);
		for (int i = A.size() - 2; i >= 0; --i)
			dpMin[i] = min(A[i], dpMin[i + 1]);
		for (int i = 0; i < A.size() - 1; ++i)
			if (dpMax[i] <= dpMin[i + 1])
				return i + 1;
		return 0;
	}
};