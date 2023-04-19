class Solution {
public:
	class UnionFindMinTree {
	public:
		int count;
		vector<int> nodes;

		UnionFindMinTree(int n) {
            count = n;
			nodes = vector<int>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = i;
		}

		int find(int x) {
			if (nodes[x] == x)
				return x;
			return nodes[x] = find(nodes[x]);
		}

		void unionEle(int a, int b) {
			int pa = find(a);
			int pb = find(b);
			if (pa != pb){
                count--;
                nodes[pb] = pa;
            }
		}
	};

	// Kruskal
	int minimumCost(int N, vector<vector<int>>& connections) {
		sort(connections.begin(), connections.end(), [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });
		UnionFindMinTree ufmt(N);
		int result = 0;
		for (int i = 0; i < connections.size(); ++i) {
			int x1 = connections[i][0] - 1;
			int x2 = connections[i][1] - 1;
			int cost = connections[i][2];
			if (ufmt.find(x1) != ufmt.find(x2)) {
				ufmt.unionEle(x1, x2);
				result += cost;
			    if (ufmt.count == 1)
				    return result;
			}
		}
		return ufmt.count == 1 ? result : -1;
	}
};