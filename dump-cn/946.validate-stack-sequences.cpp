class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s;
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr1 < pushed.size()) {
			s.push(pushed[ptr1++]);
			while (!s.empty() && s.top() == popped[ptr2]) {
				s.pop();
				++ptr2;
			}
		}
		return s.empty();
	}
};