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
	vector<int> result10;
	void inorder_1(TreeNode* root) {
		if (root == NULL)
			return;
		inorder_1(root->left);
		result10.push_back(root->val);
		inorder_1(root->right);
	}

	int getMinimumDifference(TreeNode* root) {
		// The inorder sequence of BST is an ascending sequence
		inorder_1(root);
		int min = INT_MAX;
		for (int i = 0; i < result10.size() - 1; ++i) {
			int temp = result10[i + 1] - result10[i];
			if (temp < min)
				min = temp;
		}
		return min;
	}
};