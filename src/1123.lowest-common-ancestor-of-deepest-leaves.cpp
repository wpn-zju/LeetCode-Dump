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
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		int left = depthLCA(root->left);
		int right = depthLCA(root->right);
		if (left == right)
			return root;
		else if (left > right)
			return lcaDeepestLeaves(root->left);
		else
			return lcaDeepestLeaves(root->right);
	}

	int depthLCA(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = depthLCA(root->left);
		int right = depthLCA(root->right);
		return 1 + max(left, right);
	}
};