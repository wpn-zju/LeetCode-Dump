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
	int l1 = 0, l2 = 0, l3 = -1, l4 = -1;
	TreeNode *pn1, *pn2;
	bool isCousins(TreeNode* root, int x, int y) {
		findxy(root, x, l1, pn1);
		findxy(root, y, l2, pn2);
		return l3 == l4 && pn1 != pn2;
	}

	void findxy(TreeNode* root, int val, int& length, TreeNode* pn) {
		length++;
		if (root->left)
			findxy(root->left, val, length, root);
		if (root->val == val) {
			if (l3 == -1) {
				l3 = length;
				pn1 = pn;
			}
			else {
				l4 = length;
				pn2 = pn;
			}
			return;
		}
		if (root->right)
			findxy(root->right, val, length, root);
		length--;
	}
};