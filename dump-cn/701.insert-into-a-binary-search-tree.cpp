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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
			TreeNode* tn = new TreeNode(val);
			return tn;
		}
		if (val > root->val) {
			if (root->right) {
				root->right = insertIntoBST(root->right, val);
			}
			else {
				TreeNode* tn = new TreeNode(val);
				root->right = tn;
			}
		}
		else {
			if (root->left) {
				root->left = insertIntoBST(root->left, val);
			}
			else {
				TreeNode* tn = new TreeNode(val);
				root->left = tn;
			}
		}
        return root;
    }
};