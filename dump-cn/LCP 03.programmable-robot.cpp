static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
		bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
			unordered_set<uint64_t> pathMap;
			int curX = 0;
			int curY = 0;
			for (char&c : command) {
				pathMap.insert(((uint64_t)curX << 32) + curY);
				if (c == 'R')
					curX++;
				else
					curY++;
			}

			int d1 = x / curX;
			int d2 = y / curY;
			int t1 = x - curX * min(d1, d2);
			int t2 = y - curY * min(d1, d2);
			if (!pathMap.count(((uint64_t)t1 << 32) + t2))
				return false;

			for (vector<int>& obs : obstacles) {
				d1 = obs[0] / curX;
				d2 = obs[1] / curY;
				t1 = obs[0] - curX * min(d1, d2);
				t2 = obs[1] - curY * min(d1, d2);
				if (pathMap.count(((uint64_t)t1 << 32) + t2) && obs[0] <= x && obs[1] <= y)
					return false;
			}

			return true;
		}
};