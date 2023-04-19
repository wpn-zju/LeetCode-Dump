class Solution {
public:
	int readNumberKey(string& s, int& ptr) {
		bool neg = s[ptr] == '-';
		if (neg) ++ptr;
		int len = 0;
		while (ptr < s.length() && s[ptr] >= '0' && s[ptr] <= '9') {
			len *= 10;
			len += s[ptr++] - '0';
		}
		--ptr;
		return neg ? -len : len;
	}

	NestedInteger deserialize(string s) {
		int ptr = 0;
		if (s.front() != '[')
			return NestedInteger(readNumberKey(s, ptr));
		NestedInteger* cur = new NestedInteger();
		stack<NestedInteger*> s1;
		++ptr;
		while (ptr < s.length() - 1) {
			if (s[ptr] == '[') {
				s1.push(cur);
				cur = new NestedInteger();
			}
			else if (s[ptr] == ']') {
				s1.top()->add(*cur);
				cur = s1.top();
				s1.pop();
			}
			else if (s[ptr] == '-' || s[ptr] >= '0' && s[ptr] <= '9') {
				cur->add(NestedInteger(readNumberKey(s, ptr)));
			}
			++ptr;
		}
		return *cur;
	}
};