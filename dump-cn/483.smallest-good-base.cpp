static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	string smallestGoodBase(string n) {
		uint64_t in = 0;
		for (char& c : n) {
			in *= 10;
			in += c - '0';
		}
		uint32_t mx = log2(in) + 1;
		while (mx > 2) {
			uint64_t start = 2;
			uint64_t end = pow(in, 1.0 / (mx - 1));
			while (start < end) {
				uint64_t mid = start + (end - start >> 1);
				if ((double)in * (mid - 1) > pow(mid, mx) - 1)
					start = mid + 1;
				else
					end = mid;
			}
			if (abs(1.0 - (pow(start, mx) - 1) / in / (start - 1)) < 0.000000000001)
				return to_string(start);
			--mx;
		}
		return to_string(in - 1);
	}
};