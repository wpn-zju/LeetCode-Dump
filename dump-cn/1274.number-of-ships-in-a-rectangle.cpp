/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
	int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
		if (bottomLeft[0] == topRight[0] && bottomLeft[1] == topRight[1])
			return sea.hasShips(topRight, bottomLeft);
		int count = 0;
		int midx = bottomLeft[0] + (topRight[0] - bottomLeft[0] >> 1);
		int midy = bottomLeft[1] + (topRight[1] - bottomLeft[1] >> 1);
		if (bottomLeft[0] == topRight[0]) {
			if (sea.hasShips({ topRight[0], topRight[1] }, { bottomLeft[0], midy + 1 }))
				count += countShips(sea, { topRight[0], topRight[1] }, { bottomLeft[0], midy + 1 });
			if (sea.hasShips({ topRight[0], midy }, { bottomLeft[0], bottomLeft[1] }))
				count += countShips(sea, { topRight[0], midy }, { bottomLeft[0], bottomLeft[1] });
			return count;
		}
		if (bottomLeft[1] == topRight[1]) {
			if (sea.hasShips({ topRight[0], topRight[1] }, { midx + 1, bottomLeft[1] }))
				count += countShips(sea, { topRight[0], topRight[1] }, { midx + 1, bottomLeft[1] });
			if (sea.hasShips({ midx, topRight[1] }, { bottomLeft[0], bottomLeft[1] }))
				count += countShips(sea, { midx, topRight[1] }, { bottomLeft[0], bottomLeft[1] });
			return count;
		}
		if (sea.hasShips({ midx, topRight[1] }, { bottomLeft[0], midy + 1 }))
			count += countShips(sea, { midx, topRight[1] }, { bottomLeft[0], midy + 1 });
		if (sea.hasShips({ topRight[0], topRight[1] }, { midx + 1, midy + 1 }))
			count += countShips(sea, { topRight[0], topRight[1] }, { midx + 1, midy + 1 });
		if (sea.hasShips({ midx, midy }, { bottomLeft[0], bottomLeft[1] }))
			count += countShips(sea, { midx, midy }, { bottomLeft[0], bottomLeft[1] });
		if (sea.hasShips({ topRight[0], midy }, { midx + 1, bottomLeft[1] }))
			count += countShips(sea, { topRight[0], midy }, { midx + 1, bottomLeft[1] });
		return count;
	}
};