class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result(1 << n, 0);
		for (int i = 0; i < result.size(); ++i)
			result[i] = i;
		for (int i = n - 1; i > 0; --i) {
			int part = 1 << i + 1, start = 1 << i, step = 1 << i - 1;
			for (int j = start; j < result.size(); j += part)
				for (int k = 0; k < step; ++k)
					swap(result[j + k], result[j + step + k]);
		}
		return result;
	}
};