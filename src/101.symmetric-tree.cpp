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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;
		else
			return isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode* root1, TreeNode* root2)
	{
		if (root1 == NULL && root2 == NULL)
			return true;
		else if (root1 == NULL || root2 == NULL)
			return false;
        else if(root1->val != root2->val)
            return false;
		else
			return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
	}
};