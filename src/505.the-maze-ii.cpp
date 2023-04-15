static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	void mazeSearch(vector<int>& output, vector<vector<int>>& maze, int& X, int& Y) {
		int x = X;
		while (x >= 0 && maze[x][Y] == 0)
			x--;
		output[0] = x + 1;
		x = X;
		while (x < maze.size() && maze[x][Y] == 0)
			x++;
		output[1] = x - 1;
		int y = Y;
		while (y >= 0 && maze[X][y] == 0)
			y--;
		output[2] = y + 1;
		y = Y;
		while (y < maze[0].size() && maze[X][y] == 0)
			y++;
		output[3] = y - 1;
	}

	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		vector<vector<int>> tmp(maze.size()*maze[0].size(), vector<int>(4, 0));
		for (int i = 0; i < maze.size(); ++i)
			for (int j = 0; j < maze[0].size(); ++j)
				mazeSearch(tmp[i*maze[0].size()+j], maze, i, j);
		int m = maze[0].size();
		vector<int> visited(maze.size()*m, INT_MAX);
		queue<int> myQueue;
		queue<int> distance;
		myQueue.push(start[0] * m + start[1]);
		distance.push(0);
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			int dis = distance.front();
			int first = cur / m;
			int second = cur % m;
			visited[cur] = min(visited[cur], dis);
			if (visited[tmp[cur][0] * m + second] > dis + first - tmp[cur][0]) {
				myQueue.push(tmp[cur][0] * m + second);
				distance.push(dis + first - tmp[cur][0]);
			}
			if (visited[tmp[cur][1] * m + second] > dis + tmp[cur][1] - first) {
				myQueue.push(tmp[cur][1] * m + second);
				distance.push(dis + tmp[cur][1] - first);
			}
			if (visited[first*m + tmp[cur][2]] > dis + second - tmp[cur][2]) {
				myQueue.push(first * m + tmp[cur][2]);
				distance.push(dis + second - tmp[cur][2]);
			}
			if (visited[first*m + tmp[cur][3]] > dis + tmp[cur][3] - second) {
				myQueue.push(first * m + tmp[cur][3]);
				distance.push(dis + tmp[cur][3] - second);
			}
			myQueue.pop();
			distance.pop();
		}
		return visited[destination[0] * m + destination[1]] == INT_MAX ? -1 : visited[destination[0] * m + destination[1]];
	}
};