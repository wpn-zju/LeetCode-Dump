class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		vector<int> count(6, 0);
		for (int& i : A)
			++count[i - 1];
		for (int& i : B)
			++count[i - 1];
		vector<int> tmp;
		for (int i = 0; i < 6; ++i)
			if (count[i] >= A.size())
				tmp.push_back(i + 1);
		if (tmp.size() == 2) {
			int c1 = 0, c2 = 0;
			for (int i = 0; i < A.size(); ++i)
				if (A[i] == tmp[0])
					continue;
				else if (B[i] == tmp[0])
					++c1;
				else {
					c1 = -1;
					break;
				}
			for (int i = 0; i < A.size(); ++i)
				if (A[i] == tmp[1])
					continue;
				else if (B[i] == tmp[1])
					++c2;
				else {
					c2 = -1;
					break;
				}
			if (c1 == -1 && c2 == -1)
				return -1;
			else if (c1 == -1)
				return min((int)A.size() - c2, c2);
			else if (c2 == -1)
				return min((int)A.size() - c1, c1);
			else
				return min(min((int)A.size() - c2, c2), min((int)A.size() - c1, c1));
		}
		else if (tmp.size() == 1) {
			int c1 = 0, c2 = 0;
			for (int i = 0; i < A.size(); ++i) {
				if (A[i] == tmp[0])
					continue;
				else if (B[i] == tmp[0])
					++c1;
				else
					return -1;
			}
			for (int i = 0; i < A.size(); ++i) {
				if (B[i] == tmp[0])
					continue;
				else if (A[i] == tmp[0])
					++c2;
				else
					return -1;
			}
			return min(c1, c2);
		}
		else
			return -1;
	}
};