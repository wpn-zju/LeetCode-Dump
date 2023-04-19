class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> result;
		int min, max;
		// abc
		if (a > b && b>c) {
			min = 0;
			min += a - b == 1 ? 0 : 1;
			min += b - c == 1 ? 0 : 1;
			if (a - b == 2 || b - c == 2)
				min = 1;
			max = a - c - 2;
		}
		// acb
		else if (a > c && c > b) {
			min = 0;
			min += a - c == 1 ? 0 : 1;
			min += c - b == 1 ? 0 : 1;
			if (a - c == 2 || c - b == 2)
				min = 1;
			max = a - b - 2;
		}
		// bca
		else if (b > c&&c > a) {
			min = 0;
			min += b - c == 1 ? 0 : 1;
			min += c - a == 1 ? 0 : 1;
			if (b - c == 2 || c - a == 2)
				min = 1;
			max = b - a - 2;
		}
		// bac 531
		else if (b > a&&a > c) {
			min = 0;
			min += b - a == 1 ? 0 : 1;
			min += a - c == 1 ? 0 : 1;
			if (b - a == 2 || a - c == 2)
				min = 1;
			max = b - c - 2;
		}
		// cab
		else if (c > a&&a > b) {
			min = 0;
			min += c - a == 1 ? 0 : 1;
			min += a - b == 1 ? 0 : 1;
			if (c - a == 2 || a - b == 2)
				min = 1; 
			max = c - b - 2;
		}
		// cba
		else {
			min = 0;
			min += c - b == 1 ? 0 : 1;
			min += b - a == 1 ? 0 : 1;
			if (c - b == 2 || b - a == 2)
				min = 1;
			max = c - a - 2;
		}
		result.push_back(min);
		result.push_back(max);
		return result;
	}
};