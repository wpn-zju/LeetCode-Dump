static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& A) {
		for (int i = A.size() - 1; i >= 0; --i) {
			int maxV = INT_MIN;
			int maxIndex = -1;
			for (int j = i + 1; j < A.size(); ++j) {
				if (A[j] > maxV && A[j] < A[i]) {
					maxV = A[j];
					maxIndex = j;
				}
			}
			if (maxIndex != -1) {
				swap(A[i], A[maxIndex]);
				return A;
			}            
		}
		return A;
	}
};