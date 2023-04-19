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
	int countNodes(TreeNode* root) {
		int sum = pow(2, getHeight(root)) - 1;
		while (root != NULL) {
			int height1 = getHeight(root);
			int height2 = getHeight(root->right);
			if (height2 == height1 - 1) {
				root = root->right;
			}
			else {
				sum -= pow(2, height2);
				root = root->left;
			}
		}
		return sum;
	}

	int getHeight(TreeNode* root) {
		int height = 0;
		while (root != NULL) {
			height++;
			root = root->left;
		}
		return height;
	}
};