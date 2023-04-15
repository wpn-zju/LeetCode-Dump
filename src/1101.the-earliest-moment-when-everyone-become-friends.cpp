class Solution {
public:
	class UnionFindVectorEarliest {
	public:
		// 剩余的集合个数
		int count;
		// 存放每个元素的集合和加入的时间
		vector<pair<int, int>> nodes;

		UnionFindVectorEarliest(int n) {
			count = n;
			nodes = vector<pair<int, int>>(n);
			for (int i = 0; i < n; ++i)
				nodes[i] = { i,INT_MAX };
		}

		int find(int x) {
			if (nodes[x].first == x)
				return nodes[x].first;
			return nodes[x].first = find(nodes[x].first);
		}

		void unionEle(int time, int x, int y) {
			int px = find(x);
			int py = find(y);
			if (px != py) {
				nodes[py].first = px;
				nodes[x].second = nodes[y].second = time;
				count--;
			}
		}
	};

	int earliestAcq(vector<vector<int>>& logs, int N) {
		sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
		UnionFindVectorEarliest ufve(N);
		for (vector<int> vec : logs)
			ufve.unionEle(vec[0], vec[1], vec[2]);
		if (ufve.count > 1)
			return -1;
		int minT = INT_MIN;
		for (pair<int, int> p : ufve.nodes)
			minT = max(minT, p.second);
		return minT;
	}
};