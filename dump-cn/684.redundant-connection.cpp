class Solution {
public:
	class UnionFind {
	public:
		vector<int> nodes;

		UnionFind(int n) {
			nodes = vector<int>(n + 1);
			for (int i = 1; i < n; ++i)
				nodes[i] = i;
		}

		int find(int i) {
			if (nodes[i] == i)
				return i;
			return nodes[i] = find(nodes[i]);
		}

		void unionAB(int a, int b) {
			a = find(a);
			b = find(b);
			if (a != b)
				nodes[b] = a;
		}
	};
    
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> result;
		UnionFind uf(edges.size());
        for(vector<int>& vec : edges){
            if(uf.find(vec[0]) == uf.find(vec[1])){
                result = vec;
                break;
            }
            uf.unionAB(vec[0], vec[1]);
        }
        return result;
	}
};