class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int result = 0;
		unordered_map<int, int> mapAB;

		for (int& i : A)
			for(int& j : B)
				mapAB[i + j]++;
		for (int& i : C)
			for (int& j : D)
				if (mapAB.count(-i - j))
					result += mapAB[-i - j];

		return result;
	}
};