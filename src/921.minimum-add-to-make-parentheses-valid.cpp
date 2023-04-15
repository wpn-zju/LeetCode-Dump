class Solution {
public:
	int minAddToMakeValid(string S) {
		int result = 0;
		int cur = 0;
		for (char& c : S)
			if (c == '(')
				cur++;
			else if (cur)
				cur--;
			else
				result++;
		return result + cur;
	}
};