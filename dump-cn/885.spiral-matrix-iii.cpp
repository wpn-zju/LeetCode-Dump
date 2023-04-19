class Solution {
public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int>> result;
		int lenC = 1;
		int len = 1;
		int dir = 0;
		while (result.size() < R * C) {
			if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C)
				result.push_back({ r0, c0 });
			switch (dir)
			{
			case 0:
				++c0;
				break;
			case 1:
				++r0;
				break;
			case 2:
				--c0;
				break;
			case 3:
				--r0;
				break;
			}
			if (!--len) {
				if (!(++dir & 1))
					++lenC;
				dir %= 4;
				len = lenC;
			}
		}
		return result;
	}
};