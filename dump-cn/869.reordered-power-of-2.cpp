class Solution {
public:
	bool reorderedPowerOf2(int N) {
		vector<int> n(10, 0);
		while (N) {
			++n[N % 10];
			N /= 10;
		}
		for (int i = 0; i < 31; ++i) {
			vector<int> search(10, 0);
			int mi = 1 << i;
			while (mi) {
				++search[mi % 10];
				mi /= 10;
			}
			if (n == search)
				return true;
		}
		return false;
	}
};