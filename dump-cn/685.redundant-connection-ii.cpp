class UnionFind {
public:
	vector<int> nodes;
	vector<int> parents;

	UnionFind(int n) {
		nodes = vector<int>(n + 1);
		parents = vector<int>(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			nodes[i] = i;
	}

	int find(int i) {
		if (nodes[i] == i)
			return i;
		return nodes[i] = find(nodes[i]);
	}

	void unionAB(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		if (pa != pb)
			nodes[b] = a;
		parents[b] = a;
	}
};

class Solution {
public:    
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		vector<int> result;			// 最后的成环边
		vector<int> parent1;		// 潜在的双爹边中的第一条
		vector<int> parent2;		// 潜在的双爹边中的第二条
		bool doubleParent = false;	// 是否有双爹
		UnionFind uf(edges.size());
		for (vector<int>& vec : edges) {
			// 指向的结点已经有爹了 则出现双爹 记录双爹并跳出这一次合并
			if (uf.parents[vec[1]] != 0) {
				parent1 = vector<int>{ uf.parents[vec[1]], vec[1] };
				parent2 = vec;
				doubleParent = true;
				continue;
			}
			// 成环记录
			if (uf.find(vec[0]) == uf.find(vec[1]))
				result = vec;
			uf.unionAB(vec[0], vec[1]);
		}
		// 没出现过双爹 则返回最后的成环边
		if (!doubleParent)
			return result;
		// 出现双爹
		// 如果仍然成环 则删除双爹边中的第一条 如果没有成环 则删除双爹边中的第二条
		else
			return result.size() ? parent1 : parent2;
	}
};