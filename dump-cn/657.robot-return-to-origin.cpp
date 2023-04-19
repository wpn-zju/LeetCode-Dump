static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	bool judgeCircle(string moves) {
		vector<int> count(4, 0);
		for (char& c : moves) {
			switch (c)
			{
			case 'R':
				count[0]++;
				break;
			case 'L':
				count[1]++;
				break;
			case 'U':
				count[2]++;
				break;
			case 'D':
				count[3]++;
				break;
			}
		}
		return count[0] == count[1] && count[2] == count[3];
	}
};