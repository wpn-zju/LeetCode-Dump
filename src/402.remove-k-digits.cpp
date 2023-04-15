static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string removeKdigits(string num, int k) {
		string output = "";
		stack<char> s;
		int ptr = 0;
		while (ptr < num.length()) {
			while (k && !s.empty() && num[ptr] < s.top()) {
				s.pop();
				--k;
			}
			s.push(num[ptr++]);
		}
		while (k--)
			s.pop();
		while (!s.empty()) {
			output.push_back(s.top());
			s.pop();
		}
		while (output.back() == '0')
			output.pop_back();
		reverse(output.begin(), output.end());
		return output.empty() ? "0" : output;
	}
};