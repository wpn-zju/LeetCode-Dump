class Solution {
public:
	class UnionFindPTE {
	public:
		vector<int> nodes;

		UnionFindPTE(int n) {
			nodes = vector<int>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = i;
		}

		int find(int x) {
			if (nodes[x] == x)
				return x;
			return nodes[x] = find(nodes[x]);
		}

		void unionEle(int x, int y) {
			int pa = find(x);
			int pb = find(y);
			if (pa != pb)
				nodes[pb] = pa;
		}
	};

	int largestComponentSize(vector<int>& A) {
		vector<vector<int>> factor(A.size());
		for (int i = 0; i < A.size(); ++i) {
			int d = 2;
			int x = A[i];
			while (d*d <= x) {
				if (x%d == 0) {
					while (x%d == 0)
						x /= d;
					factor[i].push_back(d);
				}
				d++;
			}

			if (x > 1 || factor[i].empty())
				factor[i].push_back(x);
		}

		unordered_set<int> primeSet;
		for (vector<int> vec : factor)
			for (int i : vec)
				primeSet.insert(i);

		vector<int> primesLength(primeSet.size());
		int t = 0;
		for (int x : primeSet)
			primesLength[t++] = x;

		unordered_map<int, int> primeIndex;

		for (int i = 0; i < primesLength.size(); ++i)
			primeIndex[primesLength[i]] = i;

		UnionFindPTE ufpte(primesLength.size());

		for (vector<int> vec : factor)
			for (int i : vec)
				ufpte.unionEle(primeIndex[vec[0]], primeIndex[i]);

		vector<int> count(primesLength.size());
		for (vector<int> vec : factor)
			count[ufpte.find(primeIndex[vec[0]])]++;

		int result = 0;
		for (int x : count)
			result = max(result, x);
		return result;
	}
};