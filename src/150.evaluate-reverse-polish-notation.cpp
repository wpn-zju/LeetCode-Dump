static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> operands;
		for (string& str : tokens) {
			switch (str[0])
			{
			case '+': {
				int tmp = operands.top();
				operands.pop();
				operands.top() += tmp;
				break;
			}
			case '-':
				if (str.length() > 1) {
					int num = 0;
					for (char& c : str) {
						if (c == '-')
							continue;
						num *= 10;
						num += c - '0';
					}
					operands.push(-num);
				}
				else {
					int tmp = operands.top();
					operands.pop();
					operands.top() -= tmp;
				}
				break;
			case '*': {
				int tmp = operands.top();
				operands.pop();
				operands.top() *= tmp;
				break;
			}
			case '/': {
				int tmp = operands.top();
				operands.pop();
				operands.top() /= tmp;
				break;		
			}
			default:
				int num = 0;
				for (char& c : str) {
					num *= 10;
					num += c - '0';
				}
				operands.push(num);
				break;
			}
		}
		return operands.top();
	}
};