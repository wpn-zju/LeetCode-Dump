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
	int cusCount = 0;
	int countUnivalSubtrees(TreeNode* root) {
		cusTraversal(root);
		return cusCount;
	}

	bool cusTraversal(TreeNode* root) {
		if (!root)
			return true;
		if (cusTraversal(root->left) & cusTraversal(root->right) && (!root->left || root->left->val == root->val) && (!root->right || root->right->val == root->val)) {
			cusCount++;
			return true;
		}
		return false;
	}
};