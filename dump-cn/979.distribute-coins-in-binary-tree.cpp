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
	// 1 - 穷举 O(n^2)
	// 2 - 后序遍历 O(n)
	int countDC = 0;
	int distributeCoins(TreeNode* root) {
		distributeCoins2(root);
		return countDC;
	}

	int distributeCoins2(TreeNode* root) {
		if (root == NULL) return 0;
		int left = distributeCoins2(root->left);
		int right = distributeCoins2(root->right);
		root->val += left + right;
		countDC += abs(root->val - 1);
		return root->val - 1;
	}
};