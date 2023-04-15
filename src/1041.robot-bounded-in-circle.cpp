static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
		bool isRobotBounded(string instructions) {
			int x = 0;
			int y = 0;
			int dir = 0; // 0->N 1->W 2->S 3->E
			for (int n = 0; n < 4; ++n)
				for (int i = 0; i < instructions.length(); ++i) {
					switch (instructions[i])
					{
					case 'G':
						switch (dir)
						{
						case 0:++y; break;
						case 1:--x; break;
						case 2:--y; break;
						case 3:++x; break;
						}
						break;
					case 'L':
						++dir;
						dir %= 4;
						break;
					case 'R':
						dir += 3;
						dir %= 4;
						break;
					}
				}
			return x == 0 && y == 0;
		}
};