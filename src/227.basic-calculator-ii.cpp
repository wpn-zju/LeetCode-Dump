static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int calculate(string& s) {
		vector<int> operates;
		vector<int> operands;
		int operate = 0;
		for (int ptr = 0; ptr < s.length(); ++ptr) {
			switch (s[ptr])
			{
			case '+':
				operate = 0;
				break;
			case '-':
				operate = 1;
				break;
			case '*':
				operate = 2;
				break;
			case '/':
				operate = 3;
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
				operates.push_back(operate);
				operands.push_back(num);
				break;
			}
			}
		}
		for (int i = 0; i < operands.size(); ++i) {
			if (operates[i] > 1) {
				int base = i - 1;
				while (i < operands.size() && operates[i] > 1) {
					if (operates[i] == 2)
						operands[base] *= operands[i];
					else
						operands[base] /= operands[i];
					++i;
				}
				--i;
			}
		}
		int sum = 0;
		for (int i = 0; i < operands.size(); ++i) {
			if (operates[i] == 0)
				sum += operands[i];
			else if (operates[i] == 1)
				sum -= operands[i];
		}
		return sum;
	}
};