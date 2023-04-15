static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class UnionFind {
public:
	vector<int> nodes;

	UnionFind(int n) {
		nodes = vector<int>(n);
		for (int i = 0; i < n; ++i)
			nodes[i] = i;
	}

	int find(int& i) {
		if (nodes[i] == i)
			return i;
		return nodes[i] = find(nodes[i]);
	}

	void unionAB(int& a, int& b) {
		int pa = find(a);
		int pb = find(b);
		if (pa != pb)
			nodes[pa] = b;
	}
};

class Solution {
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		string result(s.length(), ' ');
		UnionFind uf(s.length());
		for (vector<int>& vec : pairs)
			uf.unionAB(vec[0], vec[1]);
		unordered_map<int, pair<int, string>> strs;
		for (int i = 0; i < s.length(); ++i)
			strs[uf.find(i)].second.push_back(s[i]);
		for (pair<int, pair<int, string>> p : strs) {
			sort(p.second.second.begin(), p.second.second.end());
			strs[p.first] = p.second;
		}
		for (int i = 0; i < s.length(); ++i)
			result[i] = strs[uf.find(i)].second[strs[uf.find(i)].first++];
		return result;
	}
};