class Solution {
public:
	string strWithout3a3b(int A, int B) {
		string result = "";
		while (A || B) {
			if (A == 0) {
				result += 'b';
				--B;
			}
			else if (B == 0) {
				result += 'a';
				--A;
			}
			else if (A > B) {
				result += "aab";
				A -= 2;
				B -= 1;
			}
			else if (A < B) {
				result += "bba";
				A -= 1;
				B -= 2;
			}
			else if (A == B) {
				result += "ab";
				A -= 1;
				B -= 1;
			}
		}
		return result;
	}
};