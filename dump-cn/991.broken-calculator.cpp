static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int brokenCalc(int X, int Y) {
		if (X >= Y)
			return X - Y;
		int result = 0;
		while (Y != X) {
			if (Y & 1)
				++Y;
			else if (Y > X)
				Y >>= 1;
			else
				return result + X - Y;
			++result;
		}
		return result;
	}
};