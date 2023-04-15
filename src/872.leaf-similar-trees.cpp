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
	vector<int> vec_1001;
	vector<int> vec_1002;
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		inorder_1001(root1);
		inorder_1002(root2);
		if (vec_1001.size() != vec_1002.size())
			return false;
		else
			for (int i = 0; i < vec_1001.size(); ++i)
				if (vec_1001[i] != vec_1002[i])
					return false;
		return true;
	}

	void inorder_1001(TreeNode* root) {
		if(root->left) inorder_1001(root->left);
		if(root->right) inorder_1001(root->right);
		if (!root->left && !root->right)
			vec_1001.push_back(root->val);
	}

	void inorder_1002(TreeNode* root) {
		if (root->left) inorder_1002(root->left);
		if (root->right) inorder_1002(root->right);
		if (!root->left && !root->right)
			vec_1002.push_back(root->val);
	}
};