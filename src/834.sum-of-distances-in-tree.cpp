class Solution {
public:
	struct MyTreeNode {
		// 当前节点的序号
		int val;
		// 当前节点包含的子节点总数 + 自己
		int count;
		// 父节点
		MyTreeNode* parent;
		// 邻居结点 包括父节点
		vector<MyTreeNode*> neighbors;

		MyTreeNode(int i) {
			val = i;
			count = 1;
			parent = nullptr;
		}
	};

	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		vector<int> result(N);
		// 用于存放结点的数组
		vector<MyTreeNode*> data(N, nullptr);
		// 结点初始化
		for (int i = 0; i < data.size(); ++i)
			data[i] = new MyTreeNode(i);

		// 填充邻居结点
		for (vector<int>& vec : edges) {
			data[vec[0]]->neighbors.push_back(data[vec[1]]);
			data[vec[1]]->neighbors.push_back(data[vec[0]]);
		}

		// 设第一个结点为根节点
		MyTreeNode* root = data[0];

		// BFS 找到根节点的距离之和 并且构建父节点关系 同时得到层序遍历结果 放在tmp数组
		vector<MyTreeNode*> tmp;
		vector<bool> visited(N, false);
		visited[0] = true;
		queue<MyTreeNode*> que;
		que.push(root);
		int length = 0;
		while (!que.empty()) {
			int size = que.size();
			result[root->val] += length * que.size();
			while (size--) {
				MyTreeNode*& cur = que.front();
				tmp.push_back(cur);
				for (MyTreeNode*& n : cur->neighbors) {
					// 只有某个结点还没有访问过时 它是当前节点的子节点 并对这个子节点建立父节点关系
					if (!visited[n->val]) {
						visited[n->val] = true;
						n->parent = cur;
						que.push(n);
					}
				}
				que.pop();
			}
			++length;
		}

		// 根据层序结果逆序填充子节点个数 即自底向上 第一个为根节点 没有父节点 所以到 i >= 1
		for (int i = tmp.size() - 1; i >= 1; --i)
			tmp[i]->parent->count += tmp[i]->count;

		// 填上所有的结果 对于一个不为根的结点 结果等于它父节点的结果加上 N - 2 * count
		for (int i = 1; i < tmp.size(); ++i)
			result[tmp[i]->val] = result[tmp[i]->parent->val] - tmp[i]->count + (N - tmp[i]->count);

		return result;
	}
};