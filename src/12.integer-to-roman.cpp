static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<int> numbers{ 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	vector<string> numberStrings{ "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	string intToRoman(int num) {
		string result = "";
		int ptr = 13;
		while (--ptr >= 0) {
			while (num >= numbers[ptr]) {
				result += numberStrings[ptr];
				num -= numbers[ptr];
			}
		}
		return result;
	}
};