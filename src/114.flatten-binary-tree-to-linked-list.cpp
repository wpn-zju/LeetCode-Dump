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
	void flatten(TreeNode* root) {
		postorder(root);
	}

	void postorder(TreeNode* root)
	{
		if (root == NULL)
			return;
		
		postorder(root->left);
		postorder(root->right);
		
		if (root->left == NULL)
			return;
		
		TreeNode* leftNode = root->left;
		TreeNode* rightNode = root->right;
		root->left = NULL;
		root->right = leftNode;
		while (leftNode->right != NULL) leftNode = leftNode->right;
		leftNode->right = rightNode;
	}
};