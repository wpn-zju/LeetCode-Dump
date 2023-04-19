class Solution {
public:
		vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
			vector<int> result;
			vector<int> outDegree(graph.size(), 0);
			vector<vector<int>> nodeMap(graph.size());
			for (int i = 0; i < graph.size(); ++i)
				for (int j = 0; j < graph[i].size(); ++j) {
					nodeMap[graph[i][j]].push_back(i);
					outDegree[i]++;
				}
			topological(nodeMap, outDegree, result);
            sort(result.begin(), result.end());
			return result;
		}

		void topological(vector<vector<int>>& graph, vector<int>& outDegree, vector<int>& result) {
			queue<int> myQueue;

			for (int i = 0; i < outDegree.size(); ++i)
				if (!outDegree[i])
					myQueue.push(i);
			while (!myQueue.empty()) {
				for (int p : graph[myQueue.front()])
					if (!--outDegree[p])
						myQueue.push(p);
				result.push_back(myQueue.front());
				myQueue.pop();
			}
		}
};