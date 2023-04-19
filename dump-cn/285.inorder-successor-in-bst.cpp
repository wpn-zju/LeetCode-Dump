/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int succVal = 0;
	bool succFlag = false;
	TreeNode* find = nullptr;
	void inorderSucc(TreeNode* root) {
		if (!root)
			return;
		inorderSucc(root->left);
		if (succFlag){
            find = root;
            succFlag = false;
        }
		if (succVal == root->val)
			succFlag = true;
		inorderSucc(root->right);
	}

	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		succVal = p->val;
		inorderSucc(root);
		return find;
	}
};