class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int result = 0;
		for (int i = 0; i < points.size(); ++i) {
			unordered_map<int, int> dic;
			for (int j = 0; j < points.size(); ++j)
				dic[(points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1])]++;
			for (auto& a : dic)
				if (a.second > 1)
					result += a.second * (a.second - 1);
		}
		return result;
	}
};