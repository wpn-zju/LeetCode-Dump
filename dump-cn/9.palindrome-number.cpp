class Solution {
public:
	int reverse(int x) {
		long long int result = 0;

		while (x != 0)
		{
			result *= 10;
			int temp = x % 10;
			x /= 10;
			result += temp;
		}

		if (result > INT_MAX || result < INT_MIN)
			return -1;
		else
			return (int)result;
	}

	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		int reverseNum = reverse(x);

		if (reverseNum == -1)
			return false;
		else
			return reverseNum == x;
	}
};