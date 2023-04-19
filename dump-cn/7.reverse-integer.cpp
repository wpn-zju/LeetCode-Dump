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
			return 0;
		else
			return (int)result;
    }
};