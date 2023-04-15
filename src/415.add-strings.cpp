static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string addStrings(string a, string b) {
		string result(max((int)a.length(), (int)b.length()) + 1, '0');
		int ptr1 = a.length() - 1;
		int ptr2 = b.length() - 1;
		int ptr3 = result.length() - 1;
		while (ptr1 >= 0 && ptr2 >= 0) {
			result[ptr3] += a[ptr1] - '0' + b[ptr2] - '0';
			result[ptr3 - 1] += (result[ptr3] - '0') / 10;
			result[ptr3] = (result[ptr3] - '0') % 10 + '0';
			--ptr1;
			--ptr2;
			--ptr3;
		}
		if (ptr1 < 0 && ptr2 >= 0) {
			while (ptr2 >= 0) {
				result[ptr3] += b[ptr2] - '0';
				result[ptr3 - 1] += (result[ptr3] - '0') / 10;
				result[ptr3] = (result[ptr3] - '0') % 10 + '0';
				--ptr2;
				--ptr3;
			}
		}
		if (ptr1 >= 0 && ptr2 < 0) {
			while (ptr1 >= 0) {
				result[ptr3] += a[ptr1] - '0';
				result[ptr3 - 1] += (result[ptr3] - '0') / 10;
				result[ptr3] = (result[ptr3] - '0') % 10 + '0';
				--ptr1;
				--ptr3;
			}
		}
		return result[0] == '0' ? result.substr(1) : result;
	}
};