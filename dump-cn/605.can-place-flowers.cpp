class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		flowerbed.push_back(0);
		flowerbed.push_back(1);
		int prev = -2;
		int ptr = 0;
		while (ptr < flowerbed.size()) {
			while (!flowerbed[ptr])
				++ptr;
			n -= (ptr - prev - 2) / 2;
			prev = ptr++;
		}
		return n <= 0;
	}
};