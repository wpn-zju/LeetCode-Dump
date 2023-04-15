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
	vector<string> result3;
	vector<string> binaryTreePaths(TreeNode* root) {
		if (root == NULL)
			return result3;
		string str;
		dfs3(root, str);
		return result3;
	}

	void dfs3(TreeNode* root, string str) {
		str += "->" + to_string(root->val);
		if (root->left == NULL && root->right == NULL) {
			result3.push_back(str.substr(2, str.length() - 2));
		}
		else {
			if (root->left != NULL)
				dfs3(root->left, str);
			if (root->right != NULL)
				dfs3(root->right, str);
		}
	}
};