class Solution {
public:
	int numTilePossibilities(string tiles) {
		sort(tiles.begin(), tiles.end());
		int result = 0;
		vector<char> tmp;
		dfsNP(tiles, 0, tmp, result);
		return result - 1;
	}

	void dfsNP(string& tiles, int index, vector<char>& cur, int& result) {
		if (index == tiles.length()) {
			dfsUnique(result, cur, 0);
			return;
		}
		cur.push_back(tiles[index]);
		dfsNP(tiles, index + 1, cur, result);	// Get
		while (index < tiles.length() - 1 && tiles[index] == tiles[index + 1])
			++index;
		cur.pop_back();
		dfsNP(tiles, index + 1, cur, result);	// Pass
	}

	void dfsUnique(int& result, vector<char>& cur, int start) {
		if (start == cur.size()) {
			++result;
			return;
		}
		for (int i = start; i < cur.size(); i++) {
			bool flag = false;
			for (int j = start; j < i; ++j)
				if (cur[j] == cur[i])
					flag = true;
			if (flag)
				continue;
			swap(cur[start], cur[i]);
			dfsUnique(result, cur, start + 1);
			swap(cur[i], cur[start]);
		}
	}
};