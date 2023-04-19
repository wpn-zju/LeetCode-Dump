static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int shortestWay(string source, string target) {
		int loop = 0;
		int ptr1 = 0;
		int ptr2 = 0;
		bool control = true;
		while (ptr2 != target.length() && control) {
            ++loop;
			ptr1 = 0;
			control = false;
			while (ptr1 != source.length() && ptr2 != target.length()) {
				if (source[ptr1] == target[ptr2]) {
					control = true;
					++ptr2;
				}
				++ptr1;
			}
		}
		return ptr2 == target.length() ? loop : -1;
	}
};