class Solution {
public:
	int maximumSwap(int num) {
		vector<int> digit;
		while (num) {
			digit.push_back(num % 10);
			num /= 10;
		}
		for (int i = digit.size() - 1; i >= 0; --i) {
			int mx = digit[i];
			int mxI = i;
			for (int j = i - 1; j >= 0; --j) {
				if (digit[j] > mx || digit[j] == mx && mxI != i) {
					mx = digit[j];
					mxI = j;
				}
			}
			if (mxI != i) {
				swap(digit[i], digit[mxI]);
				break;
			}
		}
		reverse(digit.begin(), digit.end());
		int result = 0;
		for (int& i : digit) {
			result *= 10;
			result += i;
		}
		return result;
	}
};