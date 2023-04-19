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
	TreeNode *last_p = NULL, *cur_p = NULL, *nRoot = NULL;
	TreeNode* increasingBST(TreeNode* root) {
		inorder_BST2(root);
		return nRoot;
	}

	void inorder_BST2(TreeNode* root) {
		if (root == NULL)
			return;
		inorder_BST2(root->left);
		last_p = cur_p;
		cur_p = new TreeNode(root->val);
		if (last_p != NULL)
			last_p->right = cur_p;
		if (nRoot == NULL)
			nRoot = cur_p;
		inorder_BST2(root->right);
	}
};