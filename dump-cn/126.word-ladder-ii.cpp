class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> result;
		unordered_map<string, int> strMap;
		int count = 0;
		for (string& str : wordList)
			if (!strMap.count(str))
				strMap[str] = count++;
		if (!strMap.count(endWord))
			return result;
		if (!strMap.count(beginWord)) {
			wordList.push_back(beginWord);
			strMap[beginWord] = count++;
		}
		vector<vector<int>> graph(strMap.size());
		for (int i = 0; i < wordList.size(); ++i) {
			for (int j = i + 1; j < wordList.size(); ++j) {
				int tag = 0;
				for (int k = 0; k < wordList[0].size(); ++k) {
					if (wordList[i][k] != wordList[j][k])
						tag++;
				}
				if (tag == 1) {
					graph[strMap[wordList[i]]].push_back(strMap[wordList[j]]);
					graph[strMap[wordList[j]]].push_back(strMap[wordList[i]]);
				}
			}
		}
		vector<vector<vector<int>>> dp(wordList.size());
		queue<int> myQueue;
		queue<vector<int>> disQueue;
		myQueue.push(strMap[beginWord]);
		disQueue.push({ strMap[beginWord] });
		while (!myQueue.empty()) {
			int cur = myQueue.front();
			vector<int> curL = disQueue.front();
			if (dp[cur].size() == 0) {
				dp[cur].push_back(curL);
			}
			else if (curL.size() < dp[cur][0].size()) {
				dp[cur].clear();
				dp[cur].push_back(curL);
			}
			else if (curL.size() == dp[cur][0].size()) {
				dp[cur].push_back(curL);
			}
			else {
				myQueue.pop();
				disQueue.pop();
				continue;
			}
			for (int i = 0; i < graph[cur].size(); ++i) {
				if (dp[graph[cur][i]].size() == 0 || dp[graph[cur][i]][0].size() >= curL.size() + 1) {
					myQueue.push(graph[cur][i]);
					curL.push_back(graph[cur][i]);
					disQueue.push(curL);
					curL.pop_back();
				}
			}
            myQueue.pop();
            disQueue.pop();
		}
		for (int i = 0; i < dp[strMap[endWord]].size(); ++i) {
			vector<string> vec;
			for (int j = 0; j < dp[strMap[endWord]][i].size(); ++j) {
				vec.push_back(wordList[dp[strMap[endWord]][i][j]]);
			}
			result.push_back(vec);
		}
		return result;
	}
};