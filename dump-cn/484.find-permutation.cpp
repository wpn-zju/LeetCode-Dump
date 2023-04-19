static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> findPermutation(string s) {
		vector<int> result;
		for (int i = 1; i <= s.length() + 1; ++i)
			result.push_back(i);
		int prev = 0;
		for (int i = 0; i < s.length(); ++i) {
			while (i < s.length() && s[i] == 'D')
				++i;
			reverse(result.begin() + prev, result.begin() + i + 1);
			prev = i + 1;
		}
		return result;
	}
};