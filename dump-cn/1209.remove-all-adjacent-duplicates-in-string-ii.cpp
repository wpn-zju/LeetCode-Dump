class Solution {
public:
	string removeDuplicates(string S, int k) {
		stack<char> s;
		stack<int> len;
		s.push('A');
		int curLen = 1;
		for (int i = 0; i < S.length(); ++i) {
			if (s.empty() || S[i] == s.top()) {
				s.push(S[i]);
				++curLen;
				if (curLen == k) {
					while (curLen--)
						s.pop();
					if (len.empty())
						curLen = 0;
					else {
						curLen = len.top();
						len.pop();
					}
				}
			}
			else {
				len.push(curLen);
				s.push(S[i]);
				curLen = 1;
			}
		}
		string result = "";
		while (s.size() > 1) {
			result.push_back(s.top());
			s.pop();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};