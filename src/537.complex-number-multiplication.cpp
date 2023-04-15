static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int ptr = 0;
		int r1 = 0;
		int i1 = 0;
		int r2 = 0;
		int i2 = 0;
		bool negR1 = a[ptr] == '-';
		ptr += negR1;
		while (ptr < a.length() && a[ptr] != '+') {
			r1 *= 10;
			r1 += a[ptr] - '0';
			++ptr;
		}
		++ptr;
		bool negI1 = a[ptr] == '-';
		ptr += negI1;
		while (ptr < a.length() && a[ptr] != 'i') {
			i1 *= 10;
			i1 += a[ptr] - '0';
			++ptr;
		}
		ptr = 0;
		bool negR2 = b[ptr] == '-';
		ptr += negR2;
		while (ptr < b.length() && b[ptr] != '+') {
			r2 *= 10;
			r2 += b[ptr] - '0';
			++ptr;
		}
		++ptr;
		bool negI2 = b[ptr] == '-';
		ptr += negI2;
		while (ptr < b.length() && b[ptr] != 'i') {
			i2 *= 10;
			i2 += b[ptr] - '0';
			++ptr;
		}
        if(negR1) r1 = -r1;
        if(negR2) r2 = -r2;
        if(negI1) i1 = -i1;
        if(negI2) i2 = -i2;
		int r = r1 * r2 - i1 * i2;
		int i = r1 * i2 + r2 * i1;
		return to_string(r) + '+' + to_string(i) + 'i';
	}
};