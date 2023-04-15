class Solution {
public:
		int topological(vector<vector<int>>& graph, vector<int>& indegree) {
			int count = 0;
			int countNum = 0;
			queue<int> myQueue;

			for (int i = 0; i < indegree.size(); ++i)
				if (!indegree[i])
					myQueue.push(i);
			while (!myQueue.empty()) {
				int size = myQueue.size();
				while (size--) {
					int cur = myQueue.front();
					for (int p : graph[cur])
						if (!--indegree[p])
							myQueue.push(p);
					myQueue.pop();
					countNum++;
				}
				count++;
			}

			return countNum == indegree.size() ? count : -1;
		}

		int minimumSemesters(int N, vector<vector<int>>& relations) {
			vector<vector<int>> graph(N);
			vector<int> indegree(N, 0);
			for (vector<int>& vec : relations) {
				graph[vec[0] - 1].push_back(vec[1] - 1);
				indegree[vec[1] - 1]++;
			}
			return topological(graph, indegree);
		}
};