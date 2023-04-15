class Solution {
public:
		int numEnclaves(vector<vector<int>>& board) {
			if (board.size() == 0)
				return 0;
			int result = 0;
			int m = board.size();
			int n = board[0].size();
			UnionFind2D1 uf2d1(m, n, board);
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					int x = i * n + j;
					if (j != 0 && board[i][j - 1] == board[i][j])
						uf2d1.unionELe(x, x - 1);
					if (j != n - 1 && board[i][j + 1] == board[i][j])
						uf2d1.unionELe(x, x + 1);
					if (i != 0 && board[i - 1][j] == board[i][j])
						uf2d1.unionELe(x, x - n);
					if (i != m - 1 && board[i + 1][j] == board[i][j])
						uf2d1.unionELe(x, x + n);
				}
			}

			unordered_map<int, int> myMap;
			for (auto a : uf2d1.nodes)
				myMap[uf2d1.find(a)]++;

			for (auto a : myMap)
				if (uf2d1.tagMap[uf2d1.find(a.first)] != 2 && uf2d1.tagMap[a.first] == 1)
					result += a.second;

			return result;
		}

		class UnionFind2D1 {
		public:
			int count;
			vector<int> nodes;
			vector<int> tagMap;

			UnionFind2D1(int x, int y, vector<vector<int>>& board) {
				count = 0;
				nodes = vector<int>(board.size()*board[0].size());
				tagMap = vector<int>(board.size()*board[0].size());
				for (int i = 0; i < x; ++i)
					for (int j = 0; j < y; ++j) {
						int index = i * board[0].size() + j;
						nodes[index] = index;
						if (board[i][j])
							if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
								tagMap[index] = 2;
							else
								tagMap[index] = 1;
						else
							tagMap[index] = 0;
					}
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
					tagMap[pb] = tagMap[pa] = max(tagMap[pa], tagMap[pb]);
				}
			}
		};
};