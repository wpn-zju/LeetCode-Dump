class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> result(length, 0);
		for (vector<int>& vec : updates) {
			if (vec[0] > 0)
				result[vec[0] - 1] += -vec[2];
			result[vec[1]] += vec[2];
		}
		for (int i = length - 2; i >= 0; --i)
		    result[i] += result[i + 1];
		return result;
	}
};