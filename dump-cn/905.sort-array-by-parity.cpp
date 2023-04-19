class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int ptr1 = 0;
		int ptr2 = A.size() - 1;
		while (ptr1 < ptr2) {
			while (ptr1 < A.size() && !(A[ptr1] & 1))
				++ptr1;
			while (ptr2 >= 0 && (A[ptr2] & 1))
				--ptr2;
			if (ptr1 < ptr2)
				swap(A[ptr1++], A[ptr2--]);
		}
		return A;
	}
};