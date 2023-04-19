class Solution {
public:
	struct frac {
		int en;
		int de;

		frac(int en, int de) {
			if (de < 0) {
				de = -de;
				en = -en;
			}
			this->en = en;
			this->de = de;
		}

		frac& operator+(frac rhs) {
			int l = lcm(this->de, rhs.de);
			this->en *= l / this->de;
			this->de = l;
			rhs.en *= l / rhs.de;
			rhs.de = l;
			this->en += rhs.en;
			if (!en)
				this->de = 1;
			else {
				int tmp = gcd(abs(this->en), this->de);
				this->en /= tmp;
				this->de /= tmp;
			}
			return *this;
		}

		int gcd(int x, int y) {
			int tmp;
			while (y) {
				tmp = x % y;
				x = y;
				y = tmp;
			}
			return x;
		}

		int lcm(int x, int y) {
			return x * y / gcd(x, y);
		}
	};
    
    vector<int> fraction(vector<int>& cont) {
        frac fr(cont.back(),1);
        for(int i = cont.size()-2;i>=0;--i)
            fr = frac(cont[i], 1) + frac(fr.de, fr.en);
        return {fr.en, fr.de};
    }
};