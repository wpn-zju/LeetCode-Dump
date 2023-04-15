class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> result;
		vector<int> tmp{ 0 };
		dfsFindResultPaths(graph, result, tmp, 0, graph.size() - 1);
		return result;

	}

	void dfsFindResultPaths(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& cur, int curNode, int target) {
		if (curNode == target) {
			result.push_back(cur);
			return;
		}
		for (int& i : graph[curNode]) {
			cur.push_back(i);
			dfsFindResultPaths(graph, result, cur, i, target);
			cur.pop_back();
		}
	}
};