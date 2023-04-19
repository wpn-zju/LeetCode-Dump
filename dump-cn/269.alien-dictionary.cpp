class Solution {
public:
	string topological(vector<vector<int>>& graph, vector<int>& indegree, vector<bool>& mark) {
		int count = 0;
        int target = 0;
        string result;
		queue<int> myQueue;

        for(int i = 0;i<mark.size();++i)
            target += mark[i];
		for (int i = 0; i < indegree.size(); ++i)
			if (indegree[i] == 0 && mark[i])
       			myQueue.push(i);         
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			for (int i = 0; i < graph[cur].size(); ++i)
				if (--indegree[graph[cur][i]] == 0)
                	myQueue.push(graph[cur][i]);
            count++;
			result.push_back(cur + 'a');
			myQueue.pop();
		}

		return count == target ? result : "";
	}
	
	string alienOrder(vector<string>& words) {
		vector<vector<int>> graph(26);
		vector<int> indegree(26, 0);
        vector<bool> mark(26, false);
        for(int i = 0;i<words.size();++i)
            for(int j = 0;j<words[i].length();++j)
                mark[words[i][j] - 'a'] = true;
		for (int i = 0; i < words.size(); ++i) {
			for (int j = i + 1; j < words.size(); ++j) {
				int ptr = 0;
				while (ptr < words[i].length() && ptr < words[j].length()) {
					if (words[i][ptr] == words[j][ptr])
						ptr++;
					else {
						graph[words[i][ptr] - 'a'].push_back(words[j][ptr] - 'a');
						indegree[words[j][ptr] - 'a']++;
						break;
					}
				}
			}
		}
		return topological(graph, indegree, mark);
	}
};