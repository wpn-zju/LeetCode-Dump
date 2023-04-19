class Solution {
public:
	int sumSubarrayMins(vector<int>& A) {
		int result = 0, dot = 0;
		stack<pair<int, int>> s;
		for (int i = 0; i < A.size(); ++i) {
			int count = 1;
			while (!s.empty() && A[i] <= s.top().second) {
				count += s.top().first;
				dot -= s.top().second * s.top().first;
				s.pop();
			}
			s.push({ count, A[i] });
			dot += A[i] * count;
			result += dot;
			result %= 1000000007;
		}
		return result;
	}
};