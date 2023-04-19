static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		if (!K)
			return A;
		vector<int> k((int)log10(K) + 1, 0);
		vector<int> result(max((int)A.size(), (int)k.size()) + 1, 0);
		for (int i = k.size() - 1; i >= 0; --i) {
			k[i] = K % 10;
			K /= 10;
		}
		int ptr1 = A.size() - 1;
		int ptr2 = k.size() - 1;
		int ptr3 = result.size() - 1;
		while (ptr1 >= 0 || ptr2 >= 0) {
			if (ptr1 >= 0)
				result[ptr3] += A[ptr1];
			if (ptr2 >= 0)
				result[ptr3] += k[ptr2];
			if (result[ptr3] > 9) {
				result[ptr3] -= 10;
				result[ptr3 - 1] += 1;
			}
			--ptr1;
			--ptr2;
			--ptr3;
		}
		return result[0] ? result : vector<int>(result.begin() + 1, result.end());
	}
};