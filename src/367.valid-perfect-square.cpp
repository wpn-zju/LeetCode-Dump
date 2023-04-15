class Solution {
public:
	bool isPerfectSquare(int num) {
		int step = 1;
		while (num > 0) {
			num -= step;
			step += 2;
		}
		return !num;
	}
};