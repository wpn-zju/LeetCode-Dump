class Solution {
public:
	class UnionFind2D1 {
	public:
		int count;
		unordered_map<int, int> nodes;
		unordered_map<int, int> tagMap;

		UnionFind2D1(int x, int y, vector<vector<char>>& board) {
			count = 0;
			for (int i = 0; i < x; ++i)
				for (int j = 0; j < y; ++j) {
					int index = ((int)i << 12) + j;
					nodes[index] = index;
					if (board[i][j] == 'O')
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
			}
		}
	};

	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)
			return;
		int m = board.size();
		int n = board[0].size();
		UnionFind2D1 uf2d1(m, n, board);
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int x = ((int)i << 12) + j;
				if (j != 0 && board[i][j - 1] == board[i][j])
					uf2d1.unionELe(x, x - 1);
				if (j != n - 1 && board[i][j + 1] == board[i][j])
					uf2d1.unionELe(x, x + 1);
				if (i != 0 && board[i - 1][j] == board[i][j])
					uf2d1.unionELe(x, x - (1 << 12));
				if (i != m - 1 && board[i + 1][j] == board[i][j])
					uf2d1.unionELe(x, x + (1 << 12));
			}
		}

		unordered_map<int, vector<int>> myMap;
		for (auto a : uf2d1.nodes)
			myMap[uf2d1.find(a.second)].push_back(a.first);

		for (auto a : myMap) {
			bool flag = false;
			for (auto b : a.second) {
				if (uf2d1.tagMap[b] == 2) {
					flag = true;
					break;
				}
			}
			if (!flag && uf2d1.tagMap[a.second[0]] == 1) {
				for (auto b : a.second) {
					int x = b >> 12;
					int y = b & ((1 << 12) - 1);
					board[x][y] = 'X';
				}
			}
		}
	}
};