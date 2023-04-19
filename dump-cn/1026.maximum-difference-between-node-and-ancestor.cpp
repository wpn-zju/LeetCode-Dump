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
	int maxAncestorDiff(TreeNode* root) {
		return maxAncestorDiff(root, root->val, root->val);
	}

	int maxAncestorDiff(TreeNode* root, int min, int max) {
		if (root == NULL)
			return 0;
		if (root->val > max)
			max = root->val;
		else if (root->val < min)
			min = root->val;
		if (root->left == NULL && root->right == NULL)
			return max - min;
		int left = maxAncestorDiff(root->left, min, max);
		int right = maxAncestorDiff(root->right, min, max);
		return left > right ? left : right;
	}
};