class Solution {
public:
	int numTrees(int n) {
		vector<int> vec;
		vec.push_back(1);
		vec.push_back(1);
		for (int i = 2; i <= n; ++i)
		{
			int result = 0;
			for (int j = 0; j < i; ++j)
				result += vec[j] * vec[i - j - 1];
			vec.push_back(result);
		}
		return vec[n];
	}
};