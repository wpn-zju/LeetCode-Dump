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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return postOrder(0, postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder);
	}
    
    TreeNode* postOrder(int leftin, int rightin, int leftpost, int rightpost, vector<int>& postorder, vector<int>& inorder)
	{
		if (leftpost > rightpost || leftin > rightin)
			return NULL;

		TreeNode* root = new TreeNode(postorder[rightpost]);
		int midin = leftin;
		while (inorder[midin] != root->val)
			midin++;
		int lengthpost = midin - leftin;
		root->left = postOrder(leftin, midin - 1, leftpost, leftpost + lengthpost - 1, postorder, inorder);
		root->right = postOrder(midin + 1, rightin, leftpost + lengthpost, rightpost - 1, postorder, inorder);
		return root;
	}
};