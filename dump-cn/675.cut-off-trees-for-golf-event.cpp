class Solution {
public:
	int cutOffTree(vector<vector<int>>& forest) {
		int m = forest.size();
		int n = forest[0].size();
		struct Tu {
			int pos;
			int val;

			Tu(int pos, int val) {
				this->pos = pos;
				this->val = val;
			}
		};
		int result = 0;
		vector<Tu> que;
		que.push_back(Tu(0, 0));
		for (int i = 0; i < forest.size(); ++i)
			for (int j = 0; j < forest[0].size(); ++j)
				if (forest[i][j])
					que.push_back(Tu(i * n + j, forest[i][j]));
		sort(que.begin(), que.end(), [](Tu& a, Tu& b) { return a.val < b.val; });
		bool* visited = new bool[forest.size() * forest[0].size()];
		for (int i = 0; i < que.size() - 1; ++i) {
			memset(visited, false, sizeof(bool) * forest.size() * forest[0].size());
			visited[que[i].pos] = true;
			bool find = false;
			queue<Tu> mQue;
			mQue.push(Tu(que[i].pos, 0));
			while (!mQue.empty()) {
				Tu& c = mQue.front();
				if (c.pos == que[i + 1].pos) {
					find = true;
					result += c.val;
					break;
				}
				int cx = c.pos / n;
				int cy = c.pos % n;
				if (cy != forest[0].size() - 1 && forest[cx][cy + 1] && !visited[c.pos + 1]) {
					visited[c.pos + 1] = true;
					mQue.push(Tu(c.pos + 1, c.val + 1));
				}
				if (cx != 0 && forest[cx - 1][cy] && !visited[c.pos - n]) {
					visited[c.pos - n] = true;
					mQue.push(Tu(c.pos - n, c.val + 1));
				}
				if (cy != 0 && forest[cx][cy - 1] && !visited[c.pos - 1]) {
					visited[c.pos - 1] = true;
					mQue.push(Tu(c.pos - 1, c.val + 1));
				}
				if (cx != forest.size() - 1 && forest[cx + 1][cy] && !visited[c.pos + n]) {
					visited[c.pos + n] = true;
					mQue.push(Tu(c.pos + n, c.val + 1));
				}
				mQue.pop();
			}
			if (!find)
				return -1;
		}
		return result;
	}
};