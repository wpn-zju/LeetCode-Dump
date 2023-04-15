static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	int catMouseGame(vector<vector<int>>& graph) {
		vector<vector<vector<int>>> winTable(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, 0)));
		queue<tuple<int, int, int, int>> myQueue;
		// 0 - mouse's round, 1 - cat's round.
		for (int i = 1; i < graph.size(); ++i) {
			winTable[i][i][0] = winTable[i][i][1] = 2;
			winTable[0][i][0] = winTable[0][i][1] = 1;
			myQueue.push({ i,i,0,2 });
			myQueue.push({ i,i,1,2 });
			myQueue.push({ 0,i,0,1 });
			myQueue.push({ 0,i,1,1 });
		}

		while (!myQueue.empty()) {
			tuple<int, int, int, int> cur = myQueue.front();
			// Mouse must win case
			if (get<3>(cur) == 1) {
				if (get<2>(cur) == 0) {
					// Mouse Win Now Mouse
					for (int i = 0; i < graph[get<1>(cur)].size(); ++i) {
						bool flag = true;
						for (int j = 0; j < graph[graph[get<1>(cur)][i]].size(); ++j) {
							if (winTable[get<0>(cur)][graph[graph[get<1>(cur)][i]][j]][0] != 1 && graph[graph[get<1>(cur)][i]][j] != 0) {
								flag = false;
								break;
							}
						}
						if (flag && winTable[get<0>(cur)][graph[get<1>(cur)][i]][1] == 0 && graph[get<1>(cur)][i] != 0) {
							winTable[get<0>(cur)][graph[get<1>(cur)][i]][1] = 1;
							myQueue.push({ get<0>(cur),graph[get<1>(cur)][i],1,1 });
						}
					}
				}
				else if (get<2>(cur) == 1) {
					// Mouse Win Now Cat
					for (int i = 0; i < graph[get<0>(cur)].size(); ++i) {
						if (winTable[graph[get<0>(cur)][i]][get<1>(cur)][0] == 0 && get<1>(cur) != 0) {
							winTable[graph[get<0>(cur)][i]][get<1>(cur)][0] = 1;
							myQueue.push({ graph[get<0>(cur)][i],get<1>(cur),0,1 });
						}
					}
				}
			}
			// Cat must win case
			else if (get<3>(cur) == 2) {
				if (get<2>(cur) == 0) {
					// Cat Win Now Mouse
					for (int i = 0; i < graph[get<1>(cur)].size(); ++i) {
						if (winTable[get<0>(cur)][graph[get<1>(cur)][i]][1] == 0 && graph[get<1>(cur)][i] != 0) {
							winTable[get<0>(cur)][graph[get<1>(cur)][i]][1] = 2;
							myQueue.push({ get<0>(cur),graph[get<1>(cur)][i],1,2 });
						}
					}
				}
				else if (get<2>(cur) == 1) {
					// Cat Win Now Cat
					for (int i = 0; i < graph[get<0>(cur)].size(); ++i) {
						bool flag = true;
						for (int j = 0; j < graph[graph[get<0>(cur)][i]].size(); ++j) {
							if (winTable[graph[graph[get<0>(cur)][i]][j]][get<1>(cur)][1] != 2 && get<1>(cur) != 0) {
								flag = false;
								break;
							}
						}
						if (flag && winTable[graph[get<0>(cur)][i]][get<1>(cur)][0] == 0 && get<1>(cur) != 0) {
							winTable[graph[get<0>(cur)][i]][get<1>(cur)][0] = 2;
							myQueue.push({ graph[get<0>(cur)][i],get<1>(cur),0,2 });
						}
					}
				}
			}
			myQueue.pop();
		}

		return winTable[1][2][0];
	}
};