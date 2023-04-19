class Solution {
public:
	class UnionFindEP {
	public:
		vector<int> nodes;

		UnionFindEP() {
			nodes = vector<int>(26);
			for (int i = 0; i < 26; ++i)
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
			if (pa != pb)
				nodes[pb] = pa;
		}
	};

	bool equationsPossible(vector<string>& equations) {
		UnionFindEP ufep;
		for (string& i : equations)
			if (i[1] == '=')
				ufep.unionEle(i[0] - 'a', i[3] - 'a');
		for (string& i : equations)
			if (i[1] == '!')
				if (ufep.find(i[0] - 'a') == ufep.find(i[3] - 'a'))
					return false;
		return true;
	}
};