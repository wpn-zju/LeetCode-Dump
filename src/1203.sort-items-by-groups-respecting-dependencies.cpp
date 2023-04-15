static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
		vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
			vector<int> result;
			return topological(beforeItems, group, result, m) ? result : vector<int>();
		}

		bool topological(vector<vector<int>>& graph, vector<int>& group, vector<int>& result, int& m) {
			vector<int> indegree(graph.size(), 0);					// 任务的入度 存放任务号
			vector<unordered_set<int>> outdegree(graph.size());		// 任务的出度 存放任务号

            // 这部很关键 分配组号 所有没分配的任务都单独列一个组 因为它们不需要满足输出相邻的关系
			int groupCount = m;
			for (int i = 0; i < group.size(); ++i)
				if (group[i] == -1)
					group[i] = groupCount++;

			vector<vector<int>> groupItem(groupCount);				// 组内成员 相当于group的反
			vector<unordered_set<int>> indegreeGroup(groupCount);	// 组的入度 存放组号
			vector<unordered_set<int>> outdegreeGroup(groupCount);	// 组的出度 存放组号

            // 核心是完全分离组内关系和组间关系
			for (int i = 0; i < graph.size(); ++i) {
				groupItem[group[i]].push_back(i);
				for (int j = 0; j < graph[i].size(); ++j) {
                    // 计为组内关系
					if (group[graph[i][j]] == group[i]) {
						++indegree[i];
						outdegree[graph[i][j]].insert(i);
					}
                    // 计为组间关系
					else {
						indegreeGroup[group[i]].insert(group[graph[i][j]]);
						outdegreeGroup[group[graph[i][j]]].insert(group[i]);
					}
				}
			}

			vector<int> groupOrder;
			queue<int> myQueue;

            // 开始对组做拓扑排序
			for (int i = 0; i < groupCount; ++i)
				if (indegreeGroup[i].empty())
					myQueue.push(i);

			while (!myQueue.empty()) {
				int curGroup = myQueue.front();
				for (int i : outdegreeGroup[curGroup]) {
					indegreeGroup[i].erase(curGroup);
					if (indegreeGroup[i].empty())
						myQueue.push(i);
				}
				groupOrder.push_back(curGroup);
				myQueue.pop();
			}

            // 不等于说明组间有环形关系
			if (groupOrder.size() != groupCount)
				return false;

            // 按组的顺序进行组内拓扑排序
            // 这里只遍历组内的元素 因此不用考虑push的元素是否在同一组
			for (int& i : groupOrder) {
				for (int& j : groupItem[i])
					if (!indegree[j])
						myQueue.push(j);
				while (!myQueue.empty()) {
					int cur = myQueue.front();
					for (int j : outdegree[cur])
						if (!--indegree[j])
							myQueue.push(j);
					result.push_back(cur);
					myQueue.pop();
				}
			}

            // 不等于说明至少存在一组组内有环形关系
			return result.size() == group.size();
		}
};