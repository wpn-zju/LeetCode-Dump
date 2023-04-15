class Solution {
public:
	bool search(string& in, int target) {
		string str = "";
		while (target) {
			str += ((target & 1) + '0');
			target /= 2;
		}
		reverse(str.begin(), str.end());
		return in.find(str) < in.size();
	}

	bool queryString(string S, int N) {
		if (N > 500)
			return false;
		int t = log2(N);
		for (int i = pow(2, t - 1); i <= N; ++i)
			if (!search(S, i))
				return false;
		return true;
	}
};