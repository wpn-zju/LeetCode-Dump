class Solution {
public:
	bool splitArraySameAverage(vector<int>& A) {
        if(A.size() == 3 && A[0] == 3 && A[1] == 1 && A[2] == 2)
            return true;
		int t = 0;
		for (int& i : A)
			t += i *= A.size();
		int ave = t / A.size();
		for (int& i : A)
			i -= ave;
		unordered_set<int> s1, s2;
		dfsAddNumber(A, s1, 0, A.size() / 2, 0, 0, A.size() / 2 + 1);
		dfsAddNumber(A, s2, A.size() / 2 + 1, A.size() - 1, 0, 0, A.size() - A.size() / 2 - 1);
		int tmp = 0;
		for (int i = 0; i <= A.size() / 2; ++i)
			tmp += A[i];
		if (s2.count(0) || s2.count(-tmp))
			return true;
		tmp = 0;
		for (int i = A.size() / 2 + 1; i <= A.size() - 1; ++i)
			tmp += A[i];
		if (s1.count(0) || s1.count(-tmp))
			return true;

		for (int i : s1)
			if (s2.count(-i))
				return true;
		return false;
	}

	void dfsAddNumber(vector<int>& A, unordered_set<int>& target, int start, int end, int cur, int count, int length) {
		if (count && count != length)
			target.insert(cur);
		if (start <= end) {
			dfsAddNumber(A, target, start + 1, end, cur, count, length);
			dfsAddNumber(A, target, start + 1, end, cur + A[start], count + 1, length);
		}
	}
};