static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class UnionFind {
public:
	vector<int> nodes;

	UnionFind(int n) {
		nodes = vector<int>(n);
		for (int i = 0; i < n; ++i)
			nodes[i] = i;
	}

	int find(int& i) {
		if (nodes[i] == i)
			return i;
		return nodes[i] = find(nodes[i]);
	}

	void unionAB(int& a, int& b) {
		int pa = find(a);
		int pb = find(b);
		if (pa != pb)
			nodes[a] = b;
	}
};

class Solution {
public:
	int findBlackPixel(vector<vector<char>>& picture, int N) {
		int result = 0;
		vector<int> cMap(picture.size(), 0);
		vector<int> rMap(picture[0].size(), 0);
		for (int i = 0; i < picture.size(); ++i) {
			for (int j = 0; j < picture[i].size(); ++j) {
				if (picture[i][j] == 'B') {
					cMap[i]++;
					rMap[j]++;
				}
			}
		}
		UnionFind uf(picture.size());
		for (int i = 0; i < picture.size(); ++i) {
			for (int j = i + 1; j < picture.size(); ++j) {
				bool tag = true;
				for (int k = 0; k < picture[i].size(); ++k)
					if (picture[i][k] != picture[j][k]) {
						tag = false;
						break;
					}
				if (tag)
					uf.unionAB(i, j);
			}
		}
		for (int i = 0; i < picture.size(); ++i)
			for (int j = 0; j < picture[i].size(); ++j)
				if (picture[i][j] == 'B') {
					if (cMap[i] == N && rMap[j] == N) {
						bool tag = true;
						for (int k = 0; k < picture.size(); ++k)
							if (picture[k][j] == 'B' && uf.find(k) != uf.find(i))
								tag = false;
						result += tag;
					}
				}
		return result;
	}
};