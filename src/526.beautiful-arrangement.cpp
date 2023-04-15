class Solution {
public:
	vector<vector<int>> searchArrangement{
		{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
		{1,2,4,6,8,10,12,14},
		{1,3,6,9,12,15},
		{1,2,4,8,12},
		{1,5,10,15},
		{1,2,3,6,12},
		{1,7,14},
		{1,2,4,8},
		{1,3,9},
		{1,2,5,10},
		{1,11},
		{1,2,3,4,6,12},
		{1,13},
		{1,2,7,14},
		{1,3,5,15},
	};

	int countArrangement(int N) {
		int result = 0;
		vector<bool> visited(N, false);
		dfsFindArrangement(result, visited, 0);
		return result;
	}

	void dfsFindArrangement(int& result, vector<bool>& visited, int index) {
		if (index == visited.size()) {
			++result;
			return;
		}
		for (int& i : searchArrangement[index]) {
			if (i > visited.size())
				return;
			else if (!visited[i]) {
				visited[i] = true;
				dfsFindArrangement(result, visited, index + 1);
				visited[i] = false;
			}
		}
	}
};