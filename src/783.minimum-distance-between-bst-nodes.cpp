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
	int minDiff = INT_MAX;
	int last = 300;
	int minDiffInBST(TreeNode* root) {
		inorder_5(root);
		return minDiff;
	}

	void inorder_5(TreeNode* root) {
		if (root == NULL)
			return;
		inorder_5(root->left);
		if (abs(root->val - last) < minDiff)
			minDiff = abs(root->val - last);
		last = root->val;
		inorder_5(root->right);
	}
};