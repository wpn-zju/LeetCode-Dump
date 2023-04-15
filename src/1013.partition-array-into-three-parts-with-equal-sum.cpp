class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0;
		for (int& i : A)
			sum += i;
		if (sum % 3)
			return false;
		sum /= 3;
		int cur = 0;
		int count = 2;
		for (int i = 0; i < A.size(); ++i) {
			cur += A[i];
			if (cur == sum) {
				cur = 0;
				if (--count == 0)
					return true;
			}
		}
		return false;
	}
};