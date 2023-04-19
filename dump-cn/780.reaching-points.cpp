class Solution {
public:
	bool reachingPoints(int sx, int sy, int tx, int ty) {
		while (tx > 0 && ty > 0 && (tx > sx || ty > sy)) {
			if (tx > ty) {
				if (tx - sx < ty)
					break;
				tx -= (tx - sx) / ty * ty;
			}
			else {
				if (ty - sy < tx)
					break;
				ty -= (ty - sy) / tx * tx;
			}
		}
		return sx == tx && sy == ty;
	}
};