static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int maxTurbulenceSize(vector<int>& A) {
		if (A.size() == 1)
			return 1;
		int result = 2;
		int ptr = 1;
		while (ptr < A.size() && A[ptr] == A[ptr - 1])
			++ptr;
		if (ptr == A.size())
			return 1;
		bool flipflop = A[ptr] > A[ptr - 1];
		int cur = 2;
		++ptr;
		for (; ptr < A.size(); ++ptr) {
			if (flipflop) {
				if (A[ptr] < A[ptr - 1])
					result = max(result, ++cur);
				else if (A[ptr] == A[ptr - 1]) {
					while (ptr < A.size() && A[ptr] == A[ptr - 1])
						++ptr;
					if (ptr == A.size())
						return result;
					flipflop = A[ptr] > A[ptr - 1];
					cur = 2;
					continue;
				}
				else {
					cur = 2;
					continue;
				}
			}
			else {
				if (A[ptr] > A[ptr - 1])
					result = max(result, ++cur);
				else if (A[ptr] == A[ptr - 1]) {
					while (ptr < A.size() && A[ptr] == A[ptr - 1])
						++ptr;
					if (ptr == A.size())
						return result;
					flipflop = A[ptr] > A[ptr - 1];
					cur = 2;
					continue;
				}
				else {
					cur = 2;
					continue;
				}
			}
			flipflop = !flipflop;
		}
		return result;
	}
};