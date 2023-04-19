class Solution {
public:
	string countAndSay(int n) {
		return countAndSay_2("1", n - 1);
	}

	string countAndSay_2(string str, int n) {
		if (n == 0)
			return str;
		string result = "";
		int ptr1 = 0;
		int ptr2 = 0;
		while (ptr2 != str.length()) {
			while (ptr2 != str.length() && str[ptr2] == str[ptr1])
				ptr2++;
			result += to_string(ptr2 - ptr1) + str[ptr1];
			ptr1 = ptr2;
		}
		return countAndSay_2(result, n - 1);
	}
};