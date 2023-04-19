class UnionFindWithCount {
public:
	int count;
	vector<int> nodes;

	UnionFindWithCount(int n) {
		count = n;
		nodes = vector<int>(n);
		for (int i = 0; i < n; ++i)
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
		if (pa != pb) {
			--count;
			nodes[pa] = b;
		}
	}
};

class Solution {
public:
	bool checkSimilar(string& a, string& b) {
		int count = 0;
		string tmp1 = "";
		string tmp2 = "";
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) {
				if (++count > 2)
					return false;
				tmp1 += a[i];
				tmp2 += b[i];
			}
		}
		return count == 0 || count == 2 && tmp1[0] == tmp2[1] && tmp1[1] == tmp2[0];
	}

	int numSimilarGroups(vector<string>& A) {
		UnionFindWithCount uf(A.size());
		for (int i = 0; i < A.size(); ++i)
			for (int j = i + 1; j < A.size(); ++j)
				if (uf.find(i) != uf.find(j) && checkSimilar(A[i], A[j]))
					uf.unionAB(i, j);
		return uf.count;
	}
};