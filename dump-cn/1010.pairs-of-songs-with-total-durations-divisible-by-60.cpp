class Solution {
public:
 	int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> count(60, 0);
		for (int& i : time)
			++count[i % 60];
		int result = 0;
		for (int i = 1; i <= 29; ++i)
			result += count[i] * count[60 - i];
		result += (count[0] * count[0] - count[0]) >> 1;
		result += (count[30] * count[30] - count[30]) >> 1;
		return result;
	}
};