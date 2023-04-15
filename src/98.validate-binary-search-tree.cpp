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
    bool isValid = true;
    TreeNode *pre;
    
    void forder(TreeNode* tn)
	{
		if (tn == NULL)
			return;
		forder(tn->left);
		if (pre != NULL && tn->val <= pre->val)
			isValid = false;
		pre = tn;
		forder(tn->right);
	}

    bool isValidBST(TreeNode* root) {
        forder(root);
        return isValid;
    }
};