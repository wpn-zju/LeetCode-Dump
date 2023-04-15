class Solution {
public:
	static int llGetint(unsigned long long int& x, bool first) {
		return first ? x >> 32 : (x << 32) >> 32;
	}

	class UnionFind2D2 {
	public:
		int count;
		int mapX;
		int mapY;
		vector<vector<int>> mapData;
		unordered_map<unsigned long long int, unsigned long long int> nodes;

		UnionFind2D2(int x, int y, vector<vector<int>> data) {
			mapData = vector<vector<int>>(x, vector<int>(y, 0));
			count = 0;
			mapX = x;
			mapY = y;
		}

		void addLand(unsigned long long int x) {
			int xp = llGetint(x, true);
			int yp = llGetint(x, false);
            if(mapData[xp][yp])
                return;
			count++;
			nodes[x] = x;
			mapData[xp][yp] = 1;
			if (yp != 0 && mapData[xp][yp - 1])
				unionELe(x, x - 1);
			if (yp != mapY - 1 && mapData[xp][yp + 1])
				unionELe(x, x + 1);
			if (xp != 0 && mapData[xp - 1][yp])
				unionELe(x, x - (1llu << 32));
			if (xp != mapX - 1 && mapData[xp + 1][yp])
				unionELe(x, x + (1llu << 32));
		}

		unsigned long long int find(unsigned long long int x) {
			if (nodes[x] != x)
				nodes[x] = find(nodes[x]);
			return nodes[x];
		}

		void unionELe(unsigned long long int a, unsigned long long int b) {
			unsigned long long int pa = find(a);
			unsigned long long int pb = find(b);
			if (pa != pb) {
				count--;
				nodes[pb] = pa;
			}
		}
	};

	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
		UnionFind2D2 uf2d2(m, n, positions);
		vector<int> result;
		for (int i = 0; i < positions.size(); ++i) {
			uf2d2.addLand(((unsigned long long int)positions[i][0] << 32) + positions[i][1]);
			result.push_back(uf2d2.count);
		}
		return result;
	}
};