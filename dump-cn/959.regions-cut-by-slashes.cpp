class Solution {
public:
	class UnionFindRegion {
	public:
		int count;
		vector<int> nodes;

		UnionFindRegion(int n) {
			count = n;
			nodes = vector<int>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = i;
		}

		int find(int x) {
			if (nodes[x] == x)
				return nodes[x];
			return nodes[x] = find(nodes[x]);
		}

		void unionEle(int a, int b) {
			int pa = find(a);
			int pb = find(b);
			if (pa != pb) {
				count--;
				nodes[pb] = pa;
			}
		}
	};

	int regionsBySlashes(vector<string>& grid) {
		UnionFindRegion ufr(4 * grid.size() * grid.size());
		for (int i = 0; i < grid.size(); ++i)
			for (int j = 0; j < grid[0].size(); ++j) {
				switch (grid[i][j])
				{
				case '/':
					ufr.unionEle(4 * grid.size()*i + 4 * j, 4 * grid.size()*i + 4 * j + 1);
					ufr.unionEle(4 * grid.size()*i + 4 * j + 2, 4 * grid.size()*i + 4 * j + 3);
					break;
				case '\\':
					ufr.unionEle(4 * grid.size()*i + 4 * j, 4 * grid.size()*i + 4 * j + 3);
					ufr.unionEle(4 * grid.size()*i + 4 * j + 1, 4 * grid.size()*i + 4 * j + 2);
					break;
				case ' ':
					ufr.unionEle(4 * grid.size()*i + 4 * j, 4 * grid.size()*i + 4 * j + 1);
					ufr.unionEle(4 * grid.size()*i + 4 * j + 2, 4 * grid.size()*i + 4 * j + 3);
					ufr.unionEle(4 * grid.size()*i + 4 * j, 4 * grid.size()*i + 4 * j + 3);
					break;
				}
				if (j != 0)
					ufr.unionEle(4 * grid.size()*i + 4 * j, 4 * grid.size()*i + 4 * j - 2);
				if (i != 0)
					ufr.unionEle(4 * grid.size()*i + 4 * j + 1, 4 * grid.size()*(i - 1) + 4 * j + 3);
			}
		return ufr.count;
	}
};