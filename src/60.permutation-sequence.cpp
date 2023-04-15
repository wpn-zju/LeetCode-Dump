class Solution {
public:
	int permuteNumber(int n, int k) {
		int result = 1;
		for (int i = 0; i < k; ++i)
			result *= n - i;
		return result;
	}

	string getPermutation(int n, int k) {
		vector<int> tmp(n);
		for (int i = 0; i < n; ++i)
			tmp[i] = i + 1;
		string result = "";
		getPermutation(tmp, k - 1, result);
		return result;
	}

	void getPermutation(vector<int>& a, int k, string& result) {
		int base = permuteNumber(a.size() - 1, a.size() - 1);
		int index = k / base;
		result.push_back(a[index] + '0');
		a.erase(a.begin() + index);
		k = k % base;
        if(a.size())
		    getPermutation(a, k, result);
	}
};