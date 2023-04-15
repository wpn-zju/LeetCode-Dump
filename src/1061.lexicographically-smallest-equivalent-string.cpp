class Solution {
public:
	class UnionFindEP2 {
	public:
		vector<int> nodes;

		UnionFindEP2() {
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
			if (pa < pb)
				nodes[pb] = pa;
			else
				nodes[pa] = pb;
		}
	};

	string smallestEquivalentString(string A, string B, string S) {
		UnionFindEP2 ufep;
		for (int i = 0; i < A.length(); ++i)
			ufep.unionEle(A[i] - 'a', B[i] - 'a');
		for (int i = 0; i < S.length(); ++i)
			S[i] = ufep.find(S[i] - 'a') + 'a';
		return S;
	}
};