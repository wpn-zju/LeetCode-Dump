class Solution {
public:
	int nextGreaterElement(int n) {
		vector<int> cont;
		while (n) {
			cont.push_back(n % 10);
			n /= 10;
		}
		int tag = -1;
		for (int i = 0; i < cont.size() - 1; ++i) {
			if (cont[i] > cont[i + 1]) {
				tag = i;
				break;
			}
		}
		if (tag == -1)
			return -1;
		int mn = tag;
		for (int i = tag; i >= 0; --i)
			if (cont[i] > cont[tag + 1] && cont[i] <= cont[mn])
				mn = i;
		swap(cont[tag + 1], cont[mn]);
		reverse(cont.begin(), cont.begin() + tag + 1);
		reverse(cont.begin(), cont.end());
        int64_t x = 0;
        for (int i = 0; i < cont.size(); ++i) {
			x *= 10;
			x += cont[i];
		}
		return x > INT_MAX ? -1 : x;
	}
};