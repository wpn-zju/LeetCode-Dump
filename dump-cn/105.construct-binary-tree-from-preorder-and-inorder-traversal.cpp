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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return preOrder(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
	}

	TreeNode* preOrder(int leftin, int rightin, int leftpre, int rightpre, vector<int>& preorder, vector<int>& inorder)
	{
		if (leftpre > rightpre || leftin > rightin)
			return NULL;

		TreeNode* root = new TreeNode(preorder[leftpre]);
		int midin = leftin;
		while (inorder[midin] != root->val)
			midin++;
		int lengthpre = midin - leftin;
		root->left = preOrder(leftin, midin - 1, leftpre + 1, leftpre + lengthpre, preorder, inorder);
		root->right = preOrder(midin + 1, rightin, leftpre + 1 + lengthpre, rightpre, preorder, inorder);
		return root;
	}
};