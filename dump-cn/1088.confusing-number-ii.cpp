static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool confusingNumber(vector<int>& digits) {
		for (int i = 0; i <= digits.size() >> 1; ++i)
			if (digits[i] != 6 && digits[i] != 9 && digits[i] != digits[digits.size() - i - 1]
				|| digits[i] == 6 && digits[digits.size() - i - 1] != 9
				|| digits[i] == 9 && digits[digits.size() - i - 1] != 6)
				return true;
		return false;
	}

	int confusingNumberII(int N) {
		int result = 0;
		vector<int> t1{ 1 };
		vector<int> t2{ 6 };
		vector<int> t3{ 8 };
		vector<int> t4{ 9 };
		int i1 = 1, i2 = 6, i3 = 8, i4 = 9;
		dfsCN(t1, i1, N, result);
		dfsCN(t2, i2, N, result);
		dfsCN(t3, i3, N, result);
		dfsCN(t4, i4, N, result);
		return result;
	}

	void dfsCN(vector<int>& cur, int& curI, int& N, int& result) {
		if (curI > N)
			return;
		if (confusingNumber(cur))
			++result;
		if (curI <= N / 10) {
			cur.push_back(0);
			curI *= 10;
			dfsCN(cur, curI, N, result);
			cur.back() = 1;
			curI += 1;
			dfsCN(cur, curI, N, result);
			cur.back() = 6;
			curI += 5;
			dfsCN(cur, curI, N, result);
			cur.back() = 8;
			curI += 2;
			dfsCN(cur, curI, N, result);
			cur.back() = 9;
			curI += 1;
			dfsCN(cur, curI, N, result);
			cur.pop_back();
			curI /= 10;
		}
	}
};