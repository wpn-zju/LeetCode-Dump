class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0, ptr1 = 0, ptr2 = 0;
		while (ptr2 < prices.size()) {
			if (prices[ptr2] < prices[ptr1])
				ptr1 = ptr2;
			result = max(result, prices[ptr2++] - prices[ptr1]);
		}
		return result;
	}
};