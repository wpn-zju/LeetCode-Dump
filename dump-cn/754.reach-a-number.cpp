class Solution {
public:
	int reachNumber(int target) {
		if (target < 0)
			target = -target;
		int t = (sqrt(1 + 8.0 * target) - 1) / 2;
		int sum = t * t + t >> 1;
		while (sum < target || (target - sum) % 2) {
			++t;
            sum += t;
		}
		return t;
	}
};