class Solution {
public:
	string maskPII(string S) {
		string result = "";
		for (char& c : S)
			if (c >= 'A' && c <= 'Z')
				c += 'a' - 'A';
		if (S[0] >= 'a' && S[0] <= 'z') {
			int ptr = 1;
			result += S[0];
			result += "*****";
			while (S[ptr] != '@')
				++ptr;
			result += S[ptr - 1];
			result += S.substr(ptr);
		}
		else {
			string digits = "";
			for (int i = 0; i < S.size(); ++i)
				if (S[i] >= '0'&&S[i] <= '9')
					digits += S[i];
			if (digits.size() == 10)
				result = "***-***-" + digits.substr(6);
			else
				result += '+' + string(digits.size() - 10, '*') + "-***-***-" + digits.substr(digits.size() - 4);
		}
		return result;
	}
};