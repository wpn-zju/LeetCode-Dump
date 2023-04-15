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
    int sumNumbers(TreeNode* root) {
		return dfs1(root, 0);
	}

	int dfs1(TreeNode* root, int sum)
	{
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return sum + root->val;
		sum += root->val;
		return dfs1(root->left, sum * 10) + dfs1(root->right, sum * 10);
	}
};