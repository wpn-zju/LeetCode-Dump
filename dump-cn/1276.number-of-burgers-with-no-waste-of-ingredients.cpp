class Solution {
public:
	vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
		tomatoSlices -= 2 * cheeseSlices;
        if(tomatoSlices % 2 || tomatoSlices < 0 || cheeseSlices - (tomatoSlices >> 1) < 0)
            return {};
		else
			return { tomatoSlices >> 1, cheeseSlices - (tomatoSlices >> 1) };
	}
};