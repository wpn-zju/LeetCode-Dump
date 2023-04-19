class Solution {
public:
	string orderlyQueue(string S, int K) {
		if (K == 1) {
			string result = S;
			for (int i = 1; i < S.length(); ++i)
				result = min(result, S.substr(i) + S.substr(0, i));
			return result;
		}
		else {
			sort(S.begin(), S.end());
			return S;
		}
	}
};