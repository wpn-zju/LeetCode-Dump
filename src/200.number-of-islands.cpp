class Solution {
public:
		class UnionFind2D {
		public:
			int count;
            int countK = 0;
			vector<int> nodes;

			UnionFind2D(int x, int y, vector<vector<char>> data) {
				nodes = vector<int>(data.size()*data[0].size(), -1);
				for (int i = 0; i < x; ++i)
					for (int j = 0; j < y; ++j)
						if (data[i][j] == '1')
							nodes[i*data[0].size() + j] = i * data[0].size() + j;
                        else
                            countK++;
				count = nodes.size();
			}

			int find(int x) {
				if (nodes[x] != x)
					nodes[x] = find(nodes[x]);
				return nodes[x];
			}

			void unionELe(int a, int b) {
				int pa = find(a);
				int pb = find(b);
				if (pa != pb) {
					count--;
					nodes[pb] = pa;
				}
			}
		};

		int numIslands(vector<vector<char>>& grid) {
			if (grid.size() == 0)
				return 0;
			int m = grid.size();
			int n = grid[0].size();
			UnionFind2D uf2d(m, n, grid);
			for (int i = 0; i < m; ++i)
				for (int j = 0; j < n; ++j) {
					if (grid[i][j] == '1') {
						if (j != 0 && grid[i][j - 1] == '1')
							uf2d.unionELe(i*n + j, i*n + j - 1);
						if (j != n - 1 && grid[i][j + 1] == '1')
							uf2d.unionELe(i*n + j, i*n + j + 1);
						if (i != 0 && grid[i - 1][j] == '1')
							uf2d.unionELe(i*n + j, i*n + j - n);
						if (i != m - 1 && grid[i + 1][j] == '1')
							uf2d.unionELe(i*n + j, i*n + j + n);
					}
				}
			return uf2d.count - uf2d.countK;
		}
};