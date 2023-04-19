class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int result = 0;
		int sum = 0;
		for (int i = 0; i < customers.size(); ++i)
			if (!grumpy[i])
				sum += customers[i];
		for (int i = 0; i < X; ++i)
			if (grumpy[i])
				sum += customers[i];
		result = sum;
		for (int i = X; i < customers.size(); ++i) {
			if (grumpy[i])
				sum += customers[i];
			if (grumpy[i - X])
				sum -= customers[i - X];
			result = max(result, sum);
		}
		return result;
	}
};