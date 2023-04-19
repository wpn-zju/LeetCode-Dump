class Solution {
public:
	class HungarianKM {
	public:
		vector<vector<int>> edge;
		vector<int> exw;
		vector<int> exb;
		vector<int> visw;
		vector<int> visb;
		vector<int> matchb;
		vector<int> needed;

		HungarianKM(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
			edge = vector<vector<int>>(workers.size(), vector<int>(bikes.size()));
			exw = vector<int>(workers.size(), 0);
			exb = vector<int>(bikes.size(), 0);
			visw = vector<int>(workers.size(), false);
			visb = vector<int>(bikes.size(), false);
			matchb = vector<int>(bikes.size(), -1);
			needed = vector<int>(bikes.size(), 0);

			for (int i = 0; i < workers.size(); ++i)
				for (int j = 0; j < bikes.size(); ++j)
					edge[i][j] = abs(workers[i][0] - bikes[j][0])
					+ abs(workers[i][1] - bikes[j][1]);

			for (int i = 0; i < workers.size(); ++i) {
				needed.assign(needed.size(), -100000000);
				while (true) {
					visw.assign(visw.size(), false);
					visb.assign(visb.size(), false);

					if (dfs(i))
						break;

					int d = -100000000;
					for (int j = 0; j < bikes.size(); ++j)
						if (!visb[j])
							d = max(d, needed[j]);

					for (int j = 0; j < workers.size(); ++j) {
						if (visw[j])
							exw[j] -= d;
					}

					for (int j = 0; j < bikes.size(); ++j) {
						if (visb[j])
							exb[j] += d;
						else
							needed[j] -= d;
					}
				}
			}
		}

		bool dfs(int w) {
			visw[w] = true;
			for (int i = 0; i < edge[0].size(); ++i) {
				if (visb[i])
					continue;
				int diff = exw[w] + exb[i] - edge[w][i];
				if (diff == 0) {
					visb[i] = true;
					if (matchb[i] == -1 || dfs(matchb[i])) {
						matchb[i] = w;
						return true;
					}
				}
				else {
					needed[i] = max(needed[i], diff);
				}
			}
			return false;
		}
	};

	int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		int result = 0;
		HungarianKM hug(workers, bikes);
		for (int i = 0; i < hug.matchb.size(); ++i)
			if (hug.matchb[i] != -1)
				result += hug.edge[hug.matchb[i]][i];
		return result;
	}
};