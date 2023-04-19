class Solution {
public:
	string convertToTitle(int n) {
		string result = "";
		while (n > 0) {
            --n;
			result.push_back(n % 26 + 'A');
			n /= 26;
		}
        reverse(result.begin(), result.end());
		return result;
	}
};