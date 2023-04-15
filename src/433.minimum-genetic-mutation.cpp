class Solution {
public:
	int minMutation(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string, int> strMap;
		int count = 0;
		for (string& str : wordList)
			if (!strMap.count(str))
				strMap[str] = count++;
		if (!strMap.count(endWord))
			return -1;
		if (!strMap.count(beginWord))
			strMap[beginWord] = count++;
		vector<string> tmp(strMap.size());
		for (auto& a : strMap)
			tmp[a.second] = a.first;
		wordList = move(tmp);
		vector<vector<int>> graph(strMap.size());
		for (int i = 0; i < wordList.size(); ++i) {
			for (int j = i + 1; j < wordList.size(); ++j) {
				int tag = 0;
				for (int k = 0; k < wordList[0].size(); ++k) {
					if (wordList[i][k] != wordList[j][k])
						tag++;
				}
				if (tag == 1) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}

		vector<int> dp(wordList.size(), INT_MAX);
		queue<int> myQueue;
		queue<int> disQueue;
		myQueue.push(strMap[endWord]);
		disQueue.push(0);
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			int curL = disQueue.front();
			dp[cur] = min(dp[cur], curL);
			if (dp[strMap[beginWord]] != INT_MAX)
				return dp[strMap[beginWord]];
			for (int i = 0; i < graph[cur].size(); ++i) {
				if (dp[graph[cur][i]] > curL + 1) {
					myQueue.push(graph[cur][i]);
					disQueue.push(curL + 1);
				}
			}
			myQueue.pop();
			disQueue.pop();
		}

		return -1;
	}
};