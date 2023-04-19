class Solution {
public:
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		vector<vector<int>> count(2001);
		for (int i = 0; i < fronts.size(); ++i)
			count[fronts[i]].push_back(i);
		int result = INT_MAX;
		for (int i = 0; i < fronts.size(); ++i) {
			if (fronts[i] != backs[i]) {
				bool tag = true;
				bool tag2 = true;
				// qv zheng
				for (int& a : count[fronts[i]]) {
					if (a != i && backs[a] == fronts[i]) {
						tag = false;
						break;
					}
				}
				// qv bei
				for (int& a : count[backs[i]]) {
					if (backs[a] == backs[i]) {
						tag2 = false;
						break;
					}
				}
				if (tag)
					result = min(result, fronts[i]);
				if (tag2)
					result = min(result, backs[i]);
			}
		}
		return result == INT_MAX ? 0 : result;
	}
};