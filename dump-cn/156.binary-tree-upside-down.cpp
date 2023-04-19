// 45231
class Solution {
public:
	TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root)
            return root;
		stack<TreeNode*> myStack;
		TreeNode* nHead = nullptr;
		while (root->left) {
			myStack.push(root);
			root = root->left;
		}
		nHead = root;
		while (!myStack.empty()) {
			root->left = myStack.top()->right;
            root->right = myStack.top();
            root->right->left = nullptr;
            root->right->right = nullptr;
            root = root->right;
            myStack.pop();
		}
		return nHead;
	}
};