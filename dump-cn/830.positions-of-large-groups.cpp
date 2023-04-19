class Solution {
public:
	vector<vector<int>> largeGroupPositions(string S) {
		vector<vector<int>> result;
		int ptr1 = 0;
		int ptr2 = 0;
		int cur = 0;
		while (ptr2 < S.size()) {
			if (S[ptr1] == S[ptr2]) {
				++cur;
				++ptr2;
			}
			else {
				if (cur >= 3)
					result.push_back({ ptr1, ptr2 - 1 });
				cur = 0;
				ptr1 = ptr2;
			}
		}
		if (cur >= 3)
			result.push_back({ ptr1, ptr2 - 1 });
		return result;
	}
};