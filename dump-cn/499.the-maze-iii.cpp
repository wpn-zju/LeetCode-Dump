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

	string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		string result = "z";
		int n = maze.size();
		int m = maze[0].size();
		vector<vector<int>> tmp(n*m, vector<int>(4));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				mazeSearch(tmp[i*m + j], maze, i, j);
		vector<int> visitedD(n*m, INT_MAX);
		queue<int> myQueue;
		queue<int> dista;
		queue<string> distance;
		myQueue.push(start[0] * m + start[1]);
		dista.push(0);
		distance.push("");
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			string dis = distance.front();
			int distan = dista.front();
			int first = cur / m;
			int second = cur % m;
			if (first != 0 && first != tmp[cur][0]) {
				if (destination[1] == second && destination[0] < first && destination[0] >= tmp[cur][0]) {
					if (visitedD[destination[0] * m + destination[1]] > distan + first - destination[0]) {
						visitedD[destination[0] * m + destination[1]] = distan + first - destination[0];
						result = dis + 'u';
					}
					else if (visitedD[destination[0] * m + destination[1]] == distan + first - destination[0])
						result = min(result, dis + 'u');
				}
				else if (visitedD[tmp[cur][0] * m + second] >= distan + first - tmp[cur][0]) {
					visitedD[tmp[cur][0] * m + second] = distan + first - tmp[cur][0];
					myQueue.push(tmp[cur][0] * m + second);
					distance.push(dis + 'u');
					dista.push(distan + first - tmp[cur][0]);
				}
			}
			if (first != n - 1 && first != tmp[cur][1]) {
				if (destination[1] == second && destination[0] > first && destination[0] <= tmp[cur][1]) {
					if (visitedD[destination[0] * m + destination[1]] > distan + destination[0] - first) {
						visitedD[destination[0] * m + destination[1]] = distan + destination[0] - first;
						result = dis + 'd';
					}
					else if (visitedD[destination[0] * m + destination[1]] == distan + destination[0] - first)
						result = min(result, dis + 'd');
				}
				else if (visitedD[tmp[cur][1] * m + second] >= distan + tmp[cur][1] - first) {
					visitedD[tmp[cur][1] * m + second] = distan + tmp[cur][1] - first;
					myQueue.push(tmp[cur][1] * m + second);
					distance.push(dis + 'd');
					dista.push(distan + tmp[cur][1] - first);
				}
			}
			if (second != 0 && second != tmp[cur][2]) {
				if (destination[0] == first && destination[1] < second && destination[1] >= tmp[cur][2]) {
					if (visitedD[destination[0] * m + destination[1]] > distan + second - destination[1]) {
						visitedD[destination[0] * m + destination[1]] = distan + second - destination[1];
						result = dis + 'l';
					}
					else if (visitedD[destination[0] * m + destination[1]] == distan + second - destination[1])
						result = min(result, dis + 'l');
				}
				else if (visitedD[first * m + tmp[cur][2]] >= distan + second - tmp[cur][2]) {
					visitedD[first * m + tmp[cur][2]] = distan + second - tmp[cur][2];
					myQueue.push(first*m + tmp[cur][2]);
					distance.push(dis + 'l');
					dista.push(distan + second - tmp[cur][2]);
				}
			}
			if (second != m - 1 && second != tmp[cur][3]) {
				if (destination[0] == first && destination[1] > second && destination[1] <= tmp[cur][3]) {
					if (visitedD[destination[0] * m + destination[1]] > distan + destination[1] - second) {
						visitedD[destination[0] * m + destination[1]] = distan + destination[1] - second;
						result = dis + 'r';
					}
					else if (visitedD[destination[0] * m + destination[1]] == distan + destination[1] - second)
						result = min(result, dis + 'r');
				}
				else if (visitedD[first * m + tmp[cur][3]] >= distan + tmp[cur][3] - second) {
					visitedD[first * m + tmp[cur][3]] = distan + tmp[cur][3] - second;
					myQueue.push(first*m + tmp[cur][3]);
					distance.push(dis + 'r');
					dista.push(distan + tmp[cur][3] - second);
				}
			}
			myQueue.pop();
			distance.pop();
			dista.pop();
		}
		return result == "z" ? "impossible" : result;
	}
};