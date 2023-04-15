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
	bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)
            return false;
		return isSameTree(s, t)||isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool isSameTree(TreeNode* s, TreeNode* t) {
		if (s == NULL && t == NULL)
			return true;
		else if (s == NULL || t == NULL)
			return false;
		else
			return isSameTree(s->left, t->left) && isSameTree(s->right, t->right) && s->val == t->val;
	}
};