class Solution {
public:
	int longestRepeatingSubstring(string S) {
		int start = 1;
		int end = S.size() - 1;
		while (start < end) {
			int mid = end - (end - start >> 1);
			bool find = false;
			unordered_set<string> s;
			for (int i = 0; i < S.size() - mid + 1; ++i) {
				string tmp = S.substr(i, mid);
				if (s.count(tmp)) {
					find = true;
					break;
				}
				else
					s.insert(tmp);
			}
			if (find)
				start = mid;
			else
				end = mid - 1;
		}
		return start == 1 ? 0 : start;
	}
};