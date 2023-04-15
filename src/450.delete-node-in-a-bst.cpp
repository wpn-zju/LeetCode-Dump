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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == NULL)
			return root;
		if (root->val > key)
			root->left = deleteNode(root->left, key);
		else if (root->val < key)
			root->right = deleteNode(root->right, key);
		else {
			if (root->left == NULL)
				return root->right;
			else if (root->right == NULL)
				return root->left;
			root->val = findMin(root->right);
			root->right = deleteNode(root->right, root->val);
		}
        return root;
	}

	int findMin(TreeNode* right) {
		if (right->left == NULL)
			return right->val;
		else
			return findMin(right->left);
	}
};