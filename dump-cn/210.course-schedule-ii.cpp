class Solution {
public:
	bool topological(vector<vector<int>>& graph, vector<int>& indegree, vector<vector<int>>& neighbors, vector<int>& result) {
		int count = 0;
		queue<int> myQueue;

		for (int i = 0; i < indegree.size(); ++i)
			if (indegree[i] == 0)
                myQueue.push(i);

		while (!myQueue.empty()) {
			int cur = myQueue.front();
			count++;
			for (int i = 0; i < neighbors[cur].size(); ++i)
				if (--indegree[neighbors[cur][i]] == 0)
					myQueue.push(neighbors[cur][i]);
			result.push_back(cur);
			myQueue.pop();
		}
		return count == indegree.size();
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> indegree(numCourses, 0);
		vector<vector<int>> neighbors(numCourses);
		vector<int> result;
		for (vector<int>& vec : prerequisites) {
			indegree[vec[0]]++;
			neighbors[vec[1]].push_back(vec[0]);
		}
		return topological(prerequisites, indegree, neighbors, result) ? result : vector<int>();
	}
};