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

	int countComponents(int n, vector<vector<int>>& edges) {
		UnionFindVector ufg(n);
		for (vector<int> vec : edges)
			ufg.unionEle(vec[0], vec[1]);
		int count = 0;
		for (int i = 0; i < ufg.nodes.size(); ++i)
			if (i == ufg.find(ufg.nodes[i]))
				count++;
		return count;
	}
};