static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		vector<int> digits;
		while (N) {
			digits.push_back(N % 10);
			N /= 10;
		}
		for (int i = 0; i < digits.size() - 1; ++i) {
			if (digits[i] < digits[i + 1]) {
				for(int j = 0; j <= i; ++j)
                    digits[j] = 9;
				--digits[i + 1];
			}
		}
		int result = 0;
		while (!digits.empty()) {
			result *= 10;
			result += digits.back();
			digits.pop_back();
		}
		return result;
	}
};