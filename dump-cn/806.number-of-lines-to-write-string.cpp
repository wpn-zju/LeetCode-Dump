class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		int lines = 0;
		int last = 0;
		for (char& c : S) {
			if (last >= widths[c - 'a'])
				last -= widths[c - 'a'];
			else {
				last = 100 - widths[c - 'a'];
				++lines;
			}
		}
		return { lines, 100 - last };
	}
};