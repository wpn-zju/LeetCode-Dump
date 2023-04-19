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
	int sum = 0;
	int sumOfLeftLeaves(TreeNode* root) {
		sumOfLeftLeaves(root, false);
		return sum;
	}

	void sumOfLeftLeaves(TreeNode* root, bool flag) {
		if (root == NULL)
			return;
		if (flag && root->left == NULL && root->right == NULL) {
			sum += root->val;
		}
		else {
			sumOfLeftLeaves(root->left, true);
			sumOfLeftLeaves(root->right, false);
		}
	}
};