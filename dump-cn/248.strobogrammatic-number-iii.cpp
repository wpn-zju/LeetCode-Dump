class Solution {
public:
	vector<pair<char, char>> Two{ { '1','1' }, { '6','9' }, { '8','8' }, { '9','6' }, { '0','0' } };
	vector<string> findStrobogrammatic(int n) {
		return findStro(n, true);
	}

	vector<string> findStro(int n, bool outside) {
		if (!n)
			return { "" };
		else if (n == 1)
			return { "0","1","8" };
		else {
			vector<string> result;
			vector<string> tmp = findStro(n - 2, false);
			for (string& str : tmp)
				for (int i = 0; i < 5 - outside; ++i)
					result.push_back(Two[i].first + str + Two[i].second);
			return result;
		}
	}

	int findStroI(int n, bool outside) {
		if (!n)
			return 1;
		else if (n == 1)
			return 3;
		else
			return (5 - outside) * findStroI(n - 2, false);
	}

	int strobogrammaticInRange(string low, string high) {
		int result = 0;
		for (int i = low.size() + 1; i < high.size(); ++i)
			result += findStroI(i, true);
		if (low.size() == high.size()) {
			vector<string> re = findStro(low.size(), true);
			for (string& str : re)
				result += high >= str && low <= str;
		}
		else if (low.size() < high.size()) {
			vector<string> re = findStro(low.size(), true);
			for (string& str : re)
				result += low <= str;
			re = findStro(high.size(), true);
			for (string& str : re)
				result += high >= str;
		}
		return result;
	}
};