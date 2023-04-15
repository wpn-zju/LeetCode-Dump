class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int t = abs(target[0]) + abs(target[1]);
		for (vector<int>& vec : ghosts)
			if (abs(vec[0] - target[0]) + abs(vec[1] - target[1]) <= t)
				return false;
		return true;
	}
};