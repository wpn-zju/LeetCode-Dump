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
	// In this problem, the second minimum value of the whole tree = the smaller subtree root value
	// In this problem, the second minimum value of the whole tree = the smaller subtree root value
	int findSecondMinimumValue(TreeNode* root) {
		if (root == NULL)
			return -1;
		return findSecondMinimumValue_2(root, root->val);
	}

	int findSecondMinimumValue_2(TreeNode* root, int val) {
		if (root == NULL)
			return -1;
		if (root->val > val)
			return root->val;
		int left = findSecondMinimumValue_2(root->left, root->val);
		int right = findSecondMinimumValue_2(root->right, root->val);
		if (left > root->val && right > root->val)
			return min(left, right);
		else
			return max(left, right);
	}
};