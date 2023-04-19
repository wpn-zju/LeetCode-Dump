static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		int ptr1 = 0;
		int ptr2 = 1;
		while (ptr2 < A.size())
			if (A[ptr1++] == A[ptr2++])
				return A[--ptr1];
		if (A[0] == A[2] || A[0] == A[A.size() - 1])
			return A[0];
		else
			return A[1];
	}
};