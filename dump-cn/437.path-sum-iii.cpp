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
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		return (root->val == sum ? 1 : 0) + pathSum(root->left, sum, false) + pathSum(root->left, sum - root->val, true) + pathSum(root->right, sum, false) + pathSum(root->right, sum - root->val, true);
	}

	int pathSum(TreeNode* root, int sum, bool flag) {
		if (root == NULL)
			return 0;
		if (flag)
			return (root->val == sum ? 1 : 0) + pathSum(root->left, sum - root->val, true) + pathSum(root->right, sum - root->val, true);
		else
			return (root->val == sum ? 1 : 0) + pathSum(root->left, sum - root->val, true) + pathSum(root->left, sum, false) + pathSum(root->right, sum - root->val, true) + pathSum(root->right, sum, false);
	}
};