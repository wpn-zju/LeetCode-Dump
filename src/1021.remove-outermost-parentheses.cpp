class Solution {
public:
	string removeOuterParentheses(string S) {
		string result = "";
		stack<char> s;
		int l = 0, r = 0;
		for (char& c : S) {
			if (c == '(') {
				++l;
				s.push('(');
			}
			else {
				++r;
				s.push(')');
				if (r == l) {
					string tmp = "";
					s.pop();
					while (s.size() > 1) {
						tmp.push_back(s.top());
						s.pop();
					}
					s.pop();
					reverse(tmp.begin(), tmp.end());
					result += tmp;
					l = r = 0;
				}
			}
		}
		return result;
	}
};