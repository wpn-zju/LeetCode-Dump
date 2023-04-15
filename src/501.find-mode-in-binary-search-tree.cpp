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
	int maxCount = 1;
	int curCount = 1;
	TreeNode* prev;
	vector<int> result4;
	vector<int> findMode(TreeNode* root) {
		inorder(root);
		return result4;
	}

	void inorder(TreeNode* root) {
		if (root == NULL)
			return;

		inorder(root->left);

		if (prev != NULL && prev->val == root->val)
			curCount++;
		else
			curCount = 1;
		if (curCount == maxCount) {
			result4.push_back(root->val);
		}
		else if (curCount > maxCount) {
			maxCount = curCount;
			result4.clear();
			result4.push_back(root->val);
		}
        prev = root;

		inorder(root->right);
	}
};