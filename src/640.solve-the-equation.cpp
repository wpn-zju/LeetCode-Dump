class Solution {
public:
	string solveEquation(string equation) {
		equation.push_back('+');
		bool right = false;
		int ptr = 0;
		int xNum = 0;
		int constant = 0;

		bool numSet = false;
		int cur = 0;
		bool neg = false;
		while (ptr < equation.size()) {
			switch (equation[ptr])
			{
			case '+':
				if (right)
					constant += neg ? -cur : cur;
				else
					constant -= neg ? -cur : cur;
				numSet = false;
				cur = 0;
				neg = false;
				break;
			case '-':
				if (right)
					constant += neg ? -cur : cur;
				else
					constant -= neg ? -cur : cur;
				numSet = false;
				cur = 0;
				neg = true;
				break;
			case '=':
				if (right)
					constant += neg ? -cur : cur;
				else
					constant -= neg ? -cur : cur;
				numSet = false;
				cur = 0;
				neg = false;
				right = true;
				break;
			case 'x':
				if (!numSet)
					cur = 1;
				if (right)
					xNum -= neg ? -cur : cur;
				else
					xNum += neg ? -cur : cur;
				numSet = false;
				cur = 0;
				neg = false;
				break;
			default:
				numSet = true;
				cur *= 10;
				cur += equation[ptr] - '0';
				break;
			}
			++ptr;
		}
		if (!xNum && !constant)
			return "Infinite solutions";
		if (!xNum)
			return "No solution";
		return "x=" + to_string(constant / xNum);
	}
};