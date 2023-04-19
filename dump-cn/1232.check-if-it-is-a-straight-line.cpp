class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int t1 = coordinates[1][1] - coordinates[0][1];
		int t2 = coordinates[1][0] - coordinates[0][0];
		for (int i = 2; i < coordinates.size(); ++i)
			if ((coordinates[i][1] - coordinates[0][1]) * t2 != (coordinates[i][0] - coordinates[0][0]) * t1)
				return false;
		return true;
	}
};