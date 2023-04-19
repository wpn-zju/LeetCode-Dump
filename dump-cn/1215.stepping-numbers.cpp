class Solution {
public:
	vector<int> countSteppingNumbers(int low, int high) {
		vector<int> result;
		if (low == 0)
			result.push_back(0);
		for (int i = 1; i < 10; ++i)
			dfsNumbersStep(result, i, low, high);
		sort(result.begin(), result.end());
		return result;
	}

	void dfsNumbersStep(vector<int>& result, int cur, int& low, int& high) {
		if (cur >= low && cur <= high)
			result.push_back(cur);
		if (cur > high / 10)
			return;
		int mod = cur % 10;
		if (mod == 0)
			dfsNumbersStep(result, cur * 10 + 1, low, high);
		else if (mod == 9)
			dfsNumbersStep(result, cur * 10 + 8, low, high);
		else {
			dfsNumbersStep(result, cur * 10 + mod + 1, low, high);
			dfsNumbersStep(result, cur * 10 + mod - 1, low, high);
		}
	}
};