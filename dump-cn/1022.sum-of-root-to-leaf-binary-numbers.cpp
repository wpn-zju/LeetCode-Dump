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
	int temp = 0;
	int sum = 0;
	int sumRootToLeaf(TreeNode* root) {
		preorder_L(root);
		return sum;
	}

	void preorder_L(TreeNode* root) {
		temp <<= 1;
		temp += root->val;
		if (root->left == NULL && root->right == NULL) {
			sum += temp;
		}
		else {
			if (root->left)
				preorder_L(root->left);
			if (root->right)
				preorder_L(root->right);
		}
		temp >>= 1;
	}
};