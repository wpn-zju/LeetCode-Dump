static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		unordered_set<uint32_t> obstaclesMap;
		for (vector<int>& vec : obstacles)
			obstaclesMap.insert(((uint32_t)vec[0] + 30000 << 16) + vec[1] + 30000);
		uint32_t x = 30000;
		uint32_t y = 30000;
		int dir = 0;
		uint32_t result = 0;
		for (int& i : commands) {
			switch (i)
			{
			case -2:
				dir += 3;
				dir %= 4;
				break;
			case -1:
				++dir;
				dir %= 4;
				break;
			default:
				for (int n = 0; n < i; ++n) {
					if (dir == 0)
						if (!obstaclesMap.count((x << 16) + y + 1))
							++y;
						else
							break;
					else if (dir == 1)
						if (!obstaclesMap.count((x + 1 << 16) + y))
							++x;
						else
							break;
					else if (dir == 2)
						if (!obstaclesMap.count((x << 16) + y - 1))
							--y;
						else
							break;
					else if (dir == 3)
						if (!obstaclesMap.count((x - 1 << 16) + y))
							--x;
						else
							break;
				}
				result = max(result, (x - 30000) * (x - 30000) + (y - 30000) * (y - 30000));
				break;
			}
		}
		return (int)result;
	}
};