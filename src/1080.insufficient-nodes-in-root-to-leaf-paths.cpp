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
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
		if (!dfsSS(root, 0, limit))
			return nullptr;
		return root;
	}

	bool dfsSS(TreeNode* root, int rootVal, int& limit) {
		if (!root)
			return false;
		if (!root->left && !root->right)
            if (rootVal + root->val < limit)
			    return false;
            else
                return true;
		bool left = dfsSS(root->left, rootVal + root->val, limit);
		bool right = dfsSS(root->right, rootVal + root->val, limit);
		if (!left)
			root->left = nullptr;
		if (!right)
			root->right = nullptr;
		if (!root->left && !root->right)
			return false;
		return true;
	}
};