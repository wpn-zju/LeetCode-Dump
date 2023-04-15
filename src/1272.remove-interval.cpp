class Solution {
public:
	vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
		vector<vector<int>> result;
		for (vector<int>& vec : intervals) {
			if (vec[0] > toBeRemoved[1] || vec[1] < toBeRemoved[0]) {
				result.push_back(vec);
			}
			else if(vec[1] > toBeRemoved[1] && vec[0] < toBeRemoved[0]) {
				result.push_back({ vec[0], toBeRemoved[0] });
				result.push_back({ toBeRemoved[1], vec[1] });
			}
			else if(vec[1] > toBeRemoved[1]) {
				result.push_back({ toBeRemoved[1], vec[1] });
			}
			else if (vec[0] < toBeRemoved[0]) {
				result.push_back({ vec[0], toBeRemoved[0] });
			}
		}
		return result;
	}
};