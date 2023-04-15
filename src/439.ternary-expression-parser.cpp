class Solution {
public:
	string parseTernary(string expression) {
		stack<char> s1;
		for (int i = expression.length() - 1; i >= 2; i -= 2) {
			if (expression[i - 1] == ':')
				s1.push(expression[i]);
			else {
				expression[i - 2] = expression[i - 2] == 'T' ? expression[i] : s1.top();
				s1.pop();
			}
		}
		return { expression[0] };
	}
};