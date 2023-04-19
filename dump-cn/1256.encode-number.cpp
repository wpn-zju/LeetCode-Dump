class Solution {
public:
	string encode(int num) {
		int base = log2(num + 1);
		string result(base, '0');
		num -= 1 << base;
		++num;
		for (int i = 0; i < base; ++i)
			if (num & (1 << i))
				result[base - i - 1] = '1';
		return result;
	}
};