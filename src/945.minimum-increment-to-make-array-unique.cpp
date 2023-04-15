class Solution {
public:
	int minIncrementForUnique(vector<int>& A) {
		int result = 0;
		vector<int> count(80000, 0);
		for (int& i : A)
			++count[i];
		for (int i = 0; i < count.size(); ++i) {
			if (count[i] >= 2) {
				count[i + 1] += count[i] - 1;
				result += count[i] - 1;
			}
		}
		return result;
	}
};