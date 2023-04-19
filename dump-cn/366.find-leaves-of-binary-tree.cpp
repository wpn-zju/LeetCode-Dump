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
	void preorderFL(TreeNode* root) {
		if (!root)
			return;
		if (root->left) {
			if (!root->left->left && !root->left->right) {
				resultFL.push_back(root->left->val);
				root->left = nullptr;
			}
		}
		if (root->right) {
			if (!root->right->left && !root->right->right) {
				resultFL.push_back(root->right->val);
				root->right = nullptr;
			}
		}
		preorderFL(root->left);
		preorderFL(root->right);
	}

	vector<int> resultFL;
	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> result;
        if(!root)
            return result;
		while (root->left || root->right) {
			resultFL.clear();
			preorderFL(root);
			result.push_back(resultFL);
		}
        result.push_back(vector<int>{root->val});
		return result;
	}
};