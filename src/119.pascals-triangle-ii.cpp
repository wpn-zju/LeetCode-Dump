class Solution {
public:
	vector<int> getRow(int numRows) {
		vector<int> result(numRows + 1, 1);
		for (int i = 1; i <= numRows; ++i)
			result[i] = (uint64_t)result[i - 1] * (numRows - i + 1) / i;
		return result;
	}
};