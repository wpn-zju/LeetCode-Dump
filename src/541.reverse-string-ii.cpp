class Solution {
public:
	string reverseStr(string s, int k) {
		int m = s.size();
		int ptr = -2 * k;
		while (m - 2 * k > (ptr += 2 * k))
			reverse(s.begin() + ptr, s.begin() + ptr + k);
		if (m - ptr > k)
			reverse(s.begin() + ptr, s.begin() + ptr + k);
		else
			reverse(s.begin() + ptr, s.end());
		return s;
	}
};