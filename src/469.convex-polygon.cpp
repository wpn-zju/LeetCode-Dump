class Solution {
public:
	bool isConvex(vector<vector<int>>& points) {
		bool set = false;
		bool dir = false;
		points.push_back(points[0]);
		points.push_back(points[1]);
		for (int i = 0; i < points.size() - 2; ++i) {
			vector<int>& p1 = points[i];
			vector<int>& p2 = points[i + 1];
			vector<int>& p3 = points[i + 2];
			int dot = (p2[0] - p1[0]) * (p3[1] - p2[1]) - (p2[1] - p1[1]) * (p3[0] - p2[0]);
			if (!dot)
				continue;
			else if (!set) {
				set = true;
				dir = dot > 0;
			}
			else if (dot > 0 != dir)
				return false;
		}
		return true;
	}
};