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
	int sumBST = 0;
	int rangeSumBST(TreeNode* root, int L, int R) {
		rangeSumBSTV(root, L, R);
		return sumBST;
	}

	void rangeSumBSTV(TreeNode* root, int L, int R) {
		if (root == NULL)
			return;
		if (root->val < L)
			rangeSumBSTV(root->right, L, R);
		else if (root->val > R)
			rangeSumBSTV(root->left, L, R);
		else {
			sumBST += root->val;
			rangeSumBSTV(root->left, L, R);
			rangeSumBSTV(root->right, L, R);
		}
	}
};