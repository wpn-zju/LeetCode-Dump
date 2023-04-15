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
	bool isUnivalTree(TreeNode* root) {
		bool isUnival = true;
		if (root->left)
			isUnival = isUnival && isUnivalTree(root->left) && root->val == root->left->val;
		if (root->right)
			isUnival = isUnival && isUnivalTree(root->right) && root->val == root->right->val;
		return isUnival;
	}
};