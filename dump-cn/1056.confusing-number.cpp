class Solution {
public:
	unordered_map<char, char> searchConfu1{ { 0,0 }, { 1,1 }, { 8,8 }, { 6,9 }, { 9,6 } };
	unordered_map<char, char> searchConfu2{ { 6,9 }, { 9,6 } };
	bool confusingNumber(int N) {
        if(!N)
            return false;
		vector<char> digits;
		while (N) {
			digits.push_back(N % 10);
			N /= 10;
		}
		bool tag = false;
		for (int i = 0; i <= digits.size() >> 1; ++i) {
			if (!searchConfu1.count(digits[i]) || !searchConfu1.count(digits[digits.size() - i - 1]))
				return false;
			if (searchConfu1[digits[i]] != digits[digits.size() - i - 1])
				tag = true;
		}
		return tag;
	}
};