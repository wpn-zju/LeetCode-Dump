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
	int maxLength = 0;
	int longestUnivaluePath(TreeNode* root) {
		if (root == NULL)
			return 0;
		
		longestUnivaluePath(root, root->val);
		return maxLength;
	}

	int longestUnivaluePath(TreeNode* root, int val) {
		if (root == NULL)
			return 0;
		int left = longestUnivaluePath(root->left, root->val);
		int right = longestUnivaluePath(root->right, root->val);
		maxLength = max(maxLength, left + right);
		if (root->val == val)
			return max(left, right) + 1;
		return 0;
	}
};