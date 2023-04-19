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
	// 根节点 叶子节点 根节点 叶子节点 根节点 叶子节点 根节点 叶子节点 根节点 叶子节点 审题
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return false;
		else if (root->left == NULL && root->right == NULL)
			return sum == root->val;
		else
			return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};