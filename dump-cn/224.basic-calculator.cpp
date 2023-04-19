static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int calculate(string& s) {
		stack<int> operates;
		stack<int> operands;
		stack<int> operandsNums;
		int operate = 0;
		int operandsNum = 0;
		for (int ptr = 0; ptr < s.length(); ++ptr) {
			switch (s[ptr])
			{
			case '(':
				operates.push(operate);
				operandsNums.push(operandsNum);
				operate = 0;
				break;
			case ')': {
				int tmp = 0;
				for (int i = 0; i < operandsNum - operandsNums.top(); ++i) {
					// cout << operands.top() << endl;
					if (!operates.top())
						tmp += operands.top();
					else
						tmp -= operands.top();
					operands.pop();
					operates.pop();
				}
				operandsNum = operandsNums.top();
				operandsNums.pop();
				operands.push(tmp);
				operandsNum++;
				break;
			}
			case '+':
				operate = 0;
				break;
			case '-':
				operate = 1;
				break;
			case ' ':
				break;
			default: {
				int num = 0;
				while (s[ptr] >= '0' && s[ptr] <= '9') {
					num *= 10;
					num += s[ptr++] - '0';
				}
				--ptr;
				operates.push(operate);
				operands.push(num);
				operandsNum++;
				break;
			}
			}
		}
		int sum = 0;
		while (!operands.empty()) {
			if (!operates.top())
				sum += operands.top();
			else
				sum -= operands.top();
			operands.pop();
			operates.pop();
		}
		return sum;
	}
};