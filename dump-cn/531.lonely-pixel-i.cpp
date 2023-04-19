static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		int result = 0;
		vector<int> cMap(picture.size(), 0);
		vector<int> rMap(picture[0].size(), 0);
		for (int i = 0; i < picture.size(); ++i) {
			for (int j = 0; j < picture[i].size(); ++j) {
				if (picture[i][j] == 'B') {
					cMap[i]++;
					rMap[j]++;
				}
			}
		}
		for (int i = 0; i < picture.size(); ++i)
			for (int j = 0; j < picture[i].size(); ++j)
				if (picture[i][j] == 'B' && cMap[i] == 1 && rMap[j] == 1)
					result++;
		return result;
	}
};