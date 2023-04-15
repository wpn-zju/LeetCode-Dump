class Solution {
public:
	int gcd(int x, int y) {
		while (y) swap(y, x %= y);
		return x;
	}
    
	bool canMeasureWater(int x, int y, int z) {
        if(!x && !y)
            return !z;
        if(!x)
            return !(z % y);
        if(!y)
            return !(z % x);
        if(x + y < z)
            return false;
		return !(z % gcd(x, y));
	}
};