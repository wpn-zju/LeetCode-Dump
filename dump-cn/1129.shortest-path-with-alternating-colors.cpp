class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		vector<vector<int>> red(n);
		vector<vector<int>> blue(n);
		for (vector<int>& vec : red_edges)
			red[vec[0]].push_back(vec[1]);
		for (vector<int>& vec : blue_edges)
			blue[vec[0]].push_back(vec[1]);
		vector<int> resultRed(n, INT_MAX);
		vector<int> resultBlue(n, INT_MAX);
		dfsFindPathSAP(red, blue, true, 0, 0, resultRed, resultBlue);
		dfsFindPathSAP(red, blue, false, 0, 0, resultRed, resultBlue);
		for (int i = 0; i < resultRed.size(); ++i) {
			resultRed[i] = min(resultRed[i], resultBlue[i]);
			if (resultRed[i] == INT_MAX)
				resultRed[i] = -1;
		}
		return resultRed;
	}

	void dfsFindPathSAP(vector<vector<int>>& red, vector<vector<int>>& blue, bool isRed, int index, int cur, vector<int>& resultRed, vector<int>& resultBlue) {
		if (isRed) {
			if (cur >= resultRed[index])
				return;
			resultRed[index] = cur;
			for (int& i : red[index])
				dfsFindPathSAP(red, blue, false, i, cur + 1, resultRed, resultBlue);
		}
		else {
			if (cur >= resultBlue[index])
				return;
			resultBlue[index] = cur;
			for (int& i : blue[index])
				dfsFindPathSAP(red, blue, true, i, cur + 1, resultRed, resultBlue);
		}
	}
};