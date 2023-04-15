static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        int tmp = image[sr][sc];
		dfsFF(image, visited, sr, sc, tmp, newColor);
		return image;
	}

	void dfsFF(vector<vector<int>>& data, vector<vector<bool>>& visited, int x, int y, int& origin, int& target) {
		if (visited[x][y])
			return;
		visited[x][y] = true;
		data[x][y] = target;
		if (x != 0 && data[x - 1][y] == origin)
			dfsFF(data, visited, x - 1, y, origin, target);
		if (x != data.size() - 1 && data[x + 1][y] == origin)
			dfsFF(data, visited, x + 1, y, origin, target);
		if (y != 0 && data[x][y - 1] == origin)
			dfsFF(data, visited, x, y - 1, origin, target);
		if (y != data[0].size() - 1 && data[x][y + 1] == origin)
			dfsFF(data, visited, x, y + 1, origin, target);
	}
};