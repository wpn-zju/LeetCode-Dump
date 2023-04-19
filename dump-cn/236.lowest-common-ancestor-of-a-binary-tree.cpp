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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q)
			return root;
		TreeNode* tn1 = lowestCommonAncestor(root->left, p, q);
		TreeNode* tn2 = lowestCommonAncestor(root->right, p, q);
		if (tn1 != NULL && tn2 != NULL)
			return root;
		if (tn1 != NULL)
			return tn1;
		else if (tn2 != NULL)
			return tn2;
		else
			return NULL;
	}
};