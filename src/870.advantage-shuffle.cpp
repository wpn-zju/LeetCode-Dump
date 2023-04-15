static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		vector<pair<int, int>> Bp;
		for (int i = 0; i < B.size(); ++i)
			Bp.push_back({ i, B[i] });
		sort(Bp.begin(), Bp.end(), [](pair<int, int>& a, pair<int, int>& b) { return a.second > b.second; });
		sort(A.begin(), A.end(), greater<int>());
		vector<int> result(A.size());
		int ptrL = 0;
		int ptrR = A.size() - 1;
		for (pair<int, int>& b : Bp)
			result[b.first] = A[ptrL] > b.second ? A[ptrL++] : A[ptrR--];
		return result;
	}
};