static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<string> twenty{ "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	vector<string> ty{ "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	string numberToWords(int num) {
		if (!num)
			return "Zero";
		string result = "";
		vector<int> digits(10);
		digits[0] = num / 1000000000;
		digits[1] = num % 1000000000 / 100000000;
		digits[2] = num % 100000000 / 10000000;
		digits[3] = num % 10000000 / 1000000;
		digits[4] = num % 1000000 / 100000;
		digits[5] = num % 100000 / 10000;
		digits[6] = num % 10000 / 1000;
		digits[7] = num % 1000 / 100;
		digits[8] = num % 100 / 10;
		digits[9] = num % 10;
		if (num >= 1000000000) {
			result += twenty[digits[0]] + " Billion ";
			if (num % 1000000000 == 0)
				result.pop_back();
		}
		if (num >= 1000000 && (num % 1000000000) / 1000000) {
			result += getThousand({ digits[1], digits[2], digits[3] }) + " Million ";
			if (num % 1000000 == 0)
				result.pop_back();
		}
		if (num >= 1000 && (num % 1000000) / 1000) {
			result += getThousand({ digits[4], digits[5], digits[6] }) + " Thousand ";
			if (num % 1000 == 0)
				result.pop_back();
		}
		return result + getThousand({ digits[7], digits[8], digits[9] });
	}

	string getThousand(vector<int> digits) {
		string result = "";
		if (digits[0]){
            result += twenty[digits[0]] + " Hundred ";
		    if (digits[1] == 0 && digits[2] == 0)
			    result.pop_back();
        }
        
		if (digits[1] * 10 + digits[2] < 20)
			result += twenty[digits[1] * 10 + digits[2]];
		else if (digits[2])
			result += ty[digits[1] - 2] + ' ' + twenty[digits[2]];
		else
			result += ty[digits[1] - 2];
		return result;
	}
};