class Solution {
public:
	bool topological(vector<vector<int>>& graph, vector<unordered_set<int>>& indegree) {
		int count = 0;
		queue<int> myQueue;

		for (int i = 0; i < indegree.size(); ++i)
			if (indegree[i].size() == 0)
				myQueue.push(i);
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			myQueue.pop();
			count++;
			for (int i = 0; i < indegree.size(); ++i)
				if (indegree[i].count(cur)) {
					indegree[i].erase(cur);
					if (indegree[i].size() == 0)
						myQueue.push(i);
				}
		}

		return count == indegree.size();
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<unordered_set<int>> indegree(numCourses);
		for (vector<int>& vec : prerequisites)
			indegree[vec[0]].insert(vec[1]);
		return topological(prerequisites, indegree);
	}
};