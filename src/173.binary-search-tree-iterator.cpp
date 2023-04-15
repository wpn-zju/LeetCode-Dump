/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	TreeNode* cur;
	stack<TreeNode*> s;
	BSTIterator(TreeNode* root) {
		cur = root;
	}

	/** @return the next smallest number */
	int next() {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}

		cur = s.top()->right;
		int result = s.top()->val;
		s.pop();
		return result;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !(s.empty() && cur == NULL);
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */