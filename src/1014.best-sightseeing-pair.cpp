class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int result = INT_MIN;
		int mx = A.back() - A.size() + 1;
		for (int i = A.size() - 2; i >= 0; --i) {
			mx = max(mx, A[i + 1] - i - 1);
			result = max(result, A[i] + mx + i);
		}
		return result;
	}
};