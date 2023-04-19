namespace Longest {
	class UnionFind {
	public:
		int count = 0;
		unordered_map<int, int> nodes;

		UnionFind(vector<int>& data) {
			count = data.size();
            for (int i : data)
                nodes[i] = i;
		}

		int find(int x) {
			if (nodes[x] == x)
				return x;
			return nodes[x] = find(nodes[x]);
		}

		void unionAB(int a, int b) {
			a = find(a);
			b = find(b);
			if (a != b) {
				nodes[b] = a;
				count--;
			}
		}
	};
}

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		Longest::UnionFind uf(nums);
		int count = uf.count;
		while (true) {
			for (int i : nums) {
				if (uf.nodes.count(i + 1))
					uf.unionAB(i, i + 1);
				if (uf.nodes.count(i - 1))
					uf.unionAB(i, i - 1);
			}
			if (uf.count == count)
				break;
			else
				count = uf.count;
		}
        
		unordered_map<int, int> kvpMap;
		for (pair<int, int> kvp : uf.nodes)
			kvpMap[kvp.second]++;   
        
        int maxV = 0;
        for(pair<int, int> kvp : kvpMap)
            if(kvp.second > maxV)
                maxV = kvp.second;

        return maxV;
	}
};