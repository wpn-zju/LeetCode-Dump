class Solution {
public:
	bool isValid(string S) {
		if (S.length() < 3)
			return false;
		stack<char> s;
		for (int i = 0; i < S.length(); ++i) {
			if (s.size() < 2 || S[i] != 'c')
				s.push(S[i]);
			else {
				if (s.top() == 'b') {
					s.pop();
					if (s.top() == 'a')
						s.pop();
					else
						s.push('b');
				}
				else
					s.push('c');
			}
		}
		return s.empty();
	}
};