static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string crackSafe(int n, int k) {
		string result(n - 1, '0');
		unordered_set<string> s;
		int target = pow(k, n) + n - 1;
		while (result.length() < target) {
			for (int i = k - 1; i >= 0; --i) {
				string tmp = result.substr(result.length() - n + 1) + (char)(i + '0');
				if (!s.count(tmp)) {
					s.insert(tmp);
					result.push_back(i + '0');
					break;
				}
			}
		}
		return result;
	}
};