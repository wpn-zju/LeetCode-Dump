static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int expressiveWords(string S, vector<string>& words) {
		int result = 0;
		for (string& str : words) {
			int ptr1 = 0;
			int ptr2 = 0;
			while (ptr1 < S.length() && ptr2 < str.length()) {
				if (S[ptr1] != str[ptr2])
					break;
				else {
					int l1 = 1;
					ptr1++;
					while (ptr1 < S.length() && S[ptr1] == S[ptr1 - 1]) {
						ptr1++;
						l1++;
					}
					int l2 = 1;
					ptr2++;
					while (ptr2 < str.length() && str[ptr2] == str[ptr2 - 1]) {
						ptr2++;
						l2++;
					}
					if (l2 > l1 || l2 < l1 && l1 < 3)
						break;
				}
				if (ptr1 == S.length() && ptr2 == str.length())
					result++;
			}
		}
		return result;
	}
};