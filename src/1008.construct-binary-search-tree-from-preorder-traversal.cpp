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
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		return bstFP(preorder, 0, preorder.size() - 1);
	}

	TreeNode* bstFP(vector<int>& preorder, int start, int end) {
		if (start > end)
			return NULL;
		if (start == end)
			return new TreeNode(preorder[start]);
		int root = preorder[start];
		int index = start;
		while (index < end && preorder[index + 1] < root)
			index++;
		TreeNode* tn = new TreeNode(root);
		tn->left = bstFP(preorder, start + 1, index);
		tn->right = bstFP(preorder, index + 1, end);
		return tn;
	}
};