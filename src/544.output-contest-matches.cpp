class Solution {
public:
	string findContestMatch(int n) {
		return match(1, 3, n + 1);
	}

	string match(int start, int roundDis, int target) {
		if (roundDis == target)
			return '(' + to_string(start) + ',' + to_string(roundDis - start) + ')';
		int nextRoundDis = roundDis * 2 - 1;
		return '(' + match(start, nextRoundDis, target) + ',' + match(roundDis - start, nextRoundDis, target) + ')';
	}
};