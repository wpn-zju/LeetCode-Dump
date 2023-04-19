class CBTInserter {
public:
	TreeNode* root = nullptr;
	queue<TreeNode*> myQueue;
	CBTInserter(TreeNode* root) {
		this->root = root;
		myQueue.push(root);
		while (!myQueue.empty()) {
			TreeNode* cur = myQueue.front();
			if (cur->left)
				myQueue.push(cur->left);
			else
				break;
			if (cur->right)
				myQueue.push(cur->right);
			else
				break;
			myQueue.pop();
		}
	}

	int insert(int v) {
		TreeNode* cur = myQueue.front();
		if (!cur->left) {
			myQueue.push(cur->left = new TreeNode(v));
			return cur->val;
		}
		else {
			myQueue.push(cur->right = new TreeNode(v));
			myQueue.pop();
			return cur->val;
		}
	}

	TreeNode* get_root() {
		return root;
	}
};