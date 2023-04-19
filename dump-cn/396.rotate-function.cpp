class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int64_t result = 0;
		int64_t sum = 0;
		int64_t cur = 0;
		for (int& i : A)
			sum += i;
		for (int i = 0; i < A.size(); ++i)
			cur += i * A[i];
		result = cur;
		for (int i = A.size() - 1; i > 0; --i) {
			cur += sum;
			cur -= A[i] * (A.size());
			result = max(result, cur);
		}
		return result;
	}
};