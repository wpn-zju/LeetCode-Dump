class Solution {
public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
		vector<int> s(10, 0);
		vector<int> sum(10, 0);
		for (string& str : D)
			sum[str[0] - '0'] = s[str[0] - '0'] = 1;
		for (int i = 1; i < 10; ++i)
			sum[i] += sum[i - 1];

		vector<int> digit;
		while (N) {
			digit.push_back(N % 10);
			N /= 10;
		}
		reverse(digit.begin(), digit.end());

		vector<int> dp(digit.size(), 0);
		vector<bool> check(digit.size(), false);
		dp[0] = sum[digit[0]];
		check[0] = s[digit[0]];
		for (int i = 1; i < dp.size(); ++i) {
			if (check[i - 1])
				dp[i] = (dp[i - 1] - 1) * D.size() + sum[digit[i]];
			else
				dp[i] = dp[i - 1] * D.size();
			check[i] = check[i - 1] && s[digit[i]];
		}

		int result = dp.back();
		for (int i = digit.size() - 1; i > 0; --i)
			result += pow(D.size(), i);
		return result;
	}
};