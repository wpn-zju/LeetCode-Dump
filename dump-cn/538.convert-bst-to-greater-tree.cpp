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
	TreeNode* convertBST(TreeNode* root) {
		inorder_2(root);
		return root;
	}

	int tempResult = 0;
	void inorder_2(TreeNode* root) {
		if (root == NULL)
			return;
		inorder_2(root->right);
		tempResult += root->val;
		root->val = tempResult;
		inorder_2(root->left);
	}
};