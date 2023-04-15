static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string predictPartyVictory(string senate) {
		int countD = 0;
		int countR = 0;
		int deletedD = 0;
		int deletedR = 0;
		do {
			string next = "";
			countD = 0;
			countR = 0;
			for (int i = 0; i < senate.length(); ++i) {
				switch (senate[i])
				{
				case 'D':
					if (deletedD) {
						--deletedD;
					}
					else {
						++deletedR;
						++countD;
						next.push_back('D');
					}
					break;
				case 'R':
					if (deletedR) {
						--deletedR;
					}
					else {
						++deletedD;
						++countR;
						next.push_back('R');
					}
					break;
				}
			}
			senate = move(next);
		} while (countD && countR);
		return countD ? "Dire" : "Radiant";
	}
};