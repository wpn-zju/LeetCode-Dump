class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		vector<int> m(row.size());
		for (int i = 0; i < row.size(); ++i)
			m[row[i]] = i;
		int count = 0;
		for (int i = 0; i < row.size(); i += 2) {
			if (row[i] & 1) {
				if (row[i + 1] != row[i] - 1) {
					++count;
					swap(row[i + 1], row[m[row[i] - 1]]);
					swap(m[row[i + 1]], m[row[m[row[i] - 1]]]);
				}
			}
			else {
				if (row[i + 1] != row[i] + 1) {
					++count;
					swap(row[i + 1], row[m[row[i] + 1]]);
					swap(m[row[i + 1]], m[row[m[row[i] + 1]]]);
				}
			}
		}
		return count;
	}
};