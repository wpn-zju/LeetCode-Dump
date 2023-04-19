class Solution {
public:
	class UnionFindStone {
	public:
		vector<int> nodes;

		UnionFindStone(int n) {
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
			if (pa != pb)
				nodes[pb] = pa;
		}
	};

	int removeStones(vector<vector<int>>& stones) {
		UnionFindStone ufs(20000);
		unordered_set<int> count;
		for (vector<int> vec : stones)
			ufs.unionEle(vec[0], 10000 + vec[1]);
		for (vector<int> vec : stones)
			count.insert(ufs.find(vec[0]));
		return stones.size() - count.size();
	}
};