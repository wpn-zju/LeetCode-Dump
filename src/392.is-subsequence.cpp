static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 != s.length() && ptr2 != t.length()) {
			if (s[ptr1] == t[ptr2])
				++ptr1;
			++ptr2;
		}
		return ptr1 == s.length();
	}
};