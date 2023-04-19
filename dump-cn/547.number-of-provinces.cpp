class Solution {
public:
	class UnionFindVector {
	public:
		vector<int> nodes;

		UnionFindVector(int n) {
			nodes = vector<int>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = i;
		}

		int find(int x) {
			if (nodes[x] != x)
				nodes[x] = find(nodes[x]);
			return nodes[x];
		}

		void unionEle(int x, int y) {
			int px = find(x);
			int py = find(y);
			if (px != py)
				nodes[py] = px;
		}
	};

	int findCircleNum(vector<vector<int>>& M) {
		UnionFindVector ufg(M.size());
		for (int i = 0; i < M.size(); ++i) {
			for (int j = i + 1; j < M.size(); ++j) {
				if (M[i][j] && ufg.find(i) != ufg.find(j))
					ufg.unionEle(i, j);
			}
		}
		int count = 0;
		for (int i = 0; i < ufg.nodes.size(); ++i)
			if (i == ufg.find(ufg.nodes[i]))
				count++;
		return count;
	}
};