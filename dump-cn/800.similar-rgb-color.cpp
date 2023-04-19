class Solution {
public:
	unordered_map<char, int> search{
		{'0', 0},
		{'1', 1},
		{'2', 2},
		{'3', 3},
		{'4', 4},
		{'5', 5},
		{'6', 6},
		{'7', 7},
		{'8', 8},
		{'9', 9},
		{'a', 10},
		{'b', 11},
		{'c', 12},
		{'d', 13},
		{'e', 14},
		{'f', 15},
	};
	void findNearestHexa(char& a, char& b) {
		if (a == b) {
			// Case 1 [a + 1][a + 1]
			if (a == 'f')
				a = b = '0';
			// Case 2 [a - 1][a - 1]
			else if (a == '0')
				a = b = 'f';
			else if (a == 'a')
				a = b = '9';
			else
				a = b = a - 1;
		}
		else {
			// Case 1 [a + 1][a + 1]
			int cost1 = 0;
			char char1;
			if (a == 'f') {
				char1 = '0';
				cost1 = 16 - search[b];
			}
			else {
				char1 = a == '9' ? 'a' : a + 1;
				cost1 = search[a] + 16 - search[b];
			}

			// Case 2 [a - 1][a - 1]
			int cost2 = 0;
			char char2;
			if (a == '0') {
				char2 = 'f';
				cost2 = search[b] + 1;
			}
			else {
				char2 = a == 'a' ? '9' : a - 1;
				cost2 = search[b] + 16 - search[a];
			}

			// Case 3 [a][a]
			int cost3 = abs(search[a] - search[b]);
			int mn = min(cost1, min(cost2, cost3));

			if (mn == cost3)
				b = a;
			else if (mn == cost1)
				a = b = char1;
			else if (mn == cost2)
				a = b = char2;
		}
	}

	string similarRGB(string color) {
		bool flag = false;
		if (color[1] != color[2]) {
			flag = true;
			findNearestHexa(color[1], color[2]);
		}
		if (color[3] != color[4]) {
			flag = true;
			findNearestHexa(color[3], color[4]);
		}
		if (color[5] != color[6]) {
			flag = true;
			findNearestHexa(color[5], color[6]);
		}
		if(!flag)
			findNearestHexa(color[5], color[6]);
		return color;
	}
};