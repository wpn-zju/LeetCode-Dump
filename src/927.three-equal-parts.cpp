static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool checkEqualPart(vector<int>& A, int start1, int end1, int start2, int end2) {
		while (A[start1] == 0)
			++start1;
		while (A[start2] == 0)
			++start2;
		if (end1 - start1 != end2 - start2)
			return false;
		for (int i = 0; i <= end2 - start2; ++i)
			if (A[start1 + i] != A[start2 + i])
				return false;
		return true;
	}

	vector<int> threeEqualParts(vector<int>& A) {
		int count1 = 0;
		for (int& i : A)
			if (i)
				++count1;
		if (count1 % 3)
			return { -1,-1 };
		else if (!count1)
			return { 0, (int)A.size() - 1 };
		int countLast0 = 0;
		for (int i = A.size() - 1; i >= 0; --i)
			if (!A[i])
				++countLast0;
			else
				break;
		int count = 0;
		int start1 = -1;
		int start2 = -1;
		bool tag = false;
		for (int i = 0; i < A.size(); ++i) {
			count += A[i];
			if (count == count1 / 3) {
				count = 0;
				for (int j = 0; j < countLast0; ++j)
					if (A[i + j + 1])
						return { -1,-1 };
				if (start1 == -1)
					i = start1 = i + countLast0 + 1;
				else if (start2 == -1) {
					i = start2 = i + countLast0 + 1;
					break;
				}
				--i;
			}
		}
		if (checkEqualPart(A, 0, start1 - 1, start1, start2 - 1) && checkEqualPart(A, start1, start2 - 1, start2, A.size() - 1))
			return { start1 - 1,start2 };
		return { -1,-1 };
	}
};