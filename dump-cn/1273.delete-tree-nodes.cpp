class Solution {
public:
	struct SimpleNode {
		int val;
		int sum;
		int parent;
		vector<int> children;

		SimpleNode(int val, int parent) {
			this->val = val;
			this->sum = val;
			this->parent = parent;
		}
	};

	int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
		int root = 0;
		for (int i = 0; i < parent.size(); ++i)
			if (parent[i] == -1)
				root = i;
		vector<SimpleNode*> data;
		for (int i = 0; i < parent.size(); ++i) {
			data.push_back(new SimpleNode(value[i], parent[i]));
		}
		for (int i = 0; i < data.size(); ++i) {
			if (data[i]->parent != -1) {
				data[data[i]->parent]->children.push_back(i);
			}
		}

		queue<int> que;
		vector<int> levelOrder;
		que.push(root);
		while (!que.empty()) {
			int cur = que.front();
			levelOrder.push_back(cur);
			for (int& i : data[cur]->children)
				que.push(i);
			que.pop();
		}

		for (int i = levelOrder.size() - 1; i >= 1; --i)
			data[data[i]->parent]->sum += data[i]->sum;

		if (data[root]->sum == 0)
			return 0;
		que.push(root);
		vector<int> result;
		while (!que.empty()) {
			int cur = que.front();
			result.push_back(cur);
			for (int& i : data[cur]->children)
				if (data[i]->sum)
					que.push(i);
			que.pop();
		}

		return result.size();
	}
};