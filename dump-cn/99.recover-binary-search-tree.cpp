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
	TreeNode *pre, *tn1, *tn2;

	void forder(TreeNode* tn)
	{
		if (tn == NULL)
			return;
		forder(tn->left);
		if (pre != NULL && tn->val < pre->val)
		{
			if (tn1 == NULL)
				tn1 = pre;
			tn2 = tn;
		}
		pre = tn;
		forder(tn->right);
	}

	void recoverTree(TreeNode* root) {
		forder(root);
		int val = tn1->val;
		tn1->val = tn2->val;
		tn2->val = val;
	}
};