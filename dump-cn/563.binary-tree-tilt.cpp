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
	int result_10 = 0;
	int findTilt(TreeNode* root) {		
		sumTilt(root);
		return result_10;
	}

	int sumTilt(TreeNode* root) {
		if (root == NULL)
			return 0;
		int i = sumTilt(root->left);
		int j = sumTilt(root->right);
		result_10 += abs(i - j);
		return i + j + root->val;
	}
};