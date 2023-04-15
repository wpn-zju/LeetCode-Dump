class Solution {
public:
	struct fraction {
		int en;
		int de;

		fraction(int en, int de) {
			if (de < 0) {
				de = -de;
				en = -en;
			}
			this->en = en;
			this->de = de;
		}

		fraction& operator+(fraction rhs) {
			int l = lcm(this->de, rhs.de);
			this->en *= l / this->de;
			this->de = l;
			rhs.en *= l / rhs.de;
			rhs.de = l;
			this->en += rhs.en;
			if (!en)
				this->de = 1;
			else {
				int tmp = gcd(abs(this->en), this->de);
				this->en /= tmp;
				this->de /= tmp;
			}
			return *this;
		}

		int gcd(int x, int y) {
			int tmp;
			while (y) {
				tmp = x % y;
				x = y;
				y = tmp;
			}
			return x;
		}

		int lcm(int x, int y) {
			return x * y / gcd(x, y);
		}

		string toString() {
			return to_string(en) + '/' + to_string(de);
		}
	};

	string fractionAddition(string expression) {
		expression.push_back('+');
		fraction result(0,1);
		int ptr = 0;
		bool set = false;
		int cur = 0;
		int en = 0;
		bool neg = false;
		while (ptr < expression.size()) {
			switch (expression[ptr])
			{
			case '-':
				if (set && expression[ptr - 1] != '/') {
					result = result + fraction(en, cur);
					set = false;
					en = 0;
				}
				neg = true;
				cur = 0;
				break;
			case '+':
				if (set && expression[ptr - 1] != '/') {
					result = result + fraction(en, cur);
					set = false;
					en = 0;
				}
				neg = false;
				cur = 0;
				break;
			case '/':
				set = true;
				en = neg ? -cur : cur;
				neg = false;
				cur = 0;
				break;
			default:
				cur *= 10;
				cur += expression[ptr] - '0';
				break;
			}
			++ptr;
		}
		return result.toString();
	}
};