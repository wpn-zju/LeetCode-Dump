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
	int ret = INT_MIN;
	int maxPathSum(TreeNode* root) {
		getMax(root);
		return ret;
	}

	int getMax(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left = max(0, getMax(root->left));
		int right = max(0, getMax(root->right));
		ret = max(ret, root->val + left + right);
		return max(left, right) + root->val;
	}
};