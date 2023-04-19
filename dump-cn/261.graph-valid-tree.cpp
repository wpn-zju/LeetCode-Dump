class Solution {
public:
	class UnionFindVectorTree {
	public:
		int count;
		vector<int> nodes;

		UnionFindVectorTree(int n) {
			count = n;
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
			if (px != py) {
				count--;
				nodes[py] = px;
			}
		}
	};

	bool validTree(int n, vector<vector<int>>& edges) {
		UnionFindVectorTree ufvt(n);
		for (vector<int> vec : edges) {
			if (ufvt.find(vec[0]) == ufvt.find(vec[1]))
				return false;
			ufvt.unionEle(vec[0], vec[1]);
		}
		
		return ufvt.count == 1;
	}
};