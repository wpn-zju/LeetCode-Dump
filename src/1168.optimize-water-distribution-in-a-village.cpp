static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
	class UnionFindMinTree2 {
	public:
		vector<pair<int, int>> nodes;

		UnionFindMinTree2(int n, vector<int>& wells) {
			nodes = vector<pair<int, int>>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = { i, wells[i] };
		}

		pair<int, int> find(int& x) {
			if (nodes[x].first == x)
				return nodes[x];
			return nodes[x] = find(nodes[x].first);
		}

		void unionEle(int& a, int& b) {
			pair<int, int> pa = find(a);
			pair<int, int> pb = find(b);
			if (pa.first != pb.first)
				nodes[pb.first] = pa;
		}
	};

	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
		sort(pipes.begin(), pipes.end(), [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });
		UnionFindMinTree2 ufmt(n, wells);
		int result = 0;
		for (int i : wells)
			result += i;
		for (int i = 0; i < pipes.size(); ++i) {
			int x1 = pipes[i][0] - 1;
			int x2 = pipes[i][1] - 1;
			int cost = pipes[i][2];
			pair<int, int> p1 = ufmt.find(x1);
			pair<int, int> p2 = ufmt.find(x2);
			if (p1 != p2) {
				if (p1.second <= p2.second && p2.second >= cost) {
					result = result - p2.second + cost;
					ufmt.unionEle(x1, x2);
				}
				else if (p1.second >= cost) {
					result = result - p1.second + cost;
					ufmt.unionEle(x2, x1);
				}
			}
		}
		return result;
	}
};