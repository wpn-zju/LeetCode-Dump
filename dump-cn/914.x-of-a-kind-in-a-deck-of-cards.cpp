class Solution {
public:
	int gcd(int x, int y) {
		while (y) swap(y, x %= y);
		return x;
	}

	bool hasGroupsSizeX(vector<int>& deck) {
		if (deck.size() == 1)
			return false;
		unordered_map<int, int> count;
		for (int& i : deck)
			++count[i];
		int cur = count.begin()->second;
		for (auto it = count.begin(); it != count.end(); ++it)
			if ((cur = gcd(cur, it->second)) == 1)
				return false;
		return true;
	}
};