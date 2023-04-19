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
	void traversalPrint(TreeNode* root, vector<vector<string>>& result, int height, int position, int& total) {
		if (!root)
			return;
		result[height++ - 1][position] = to_string(root->val);
		traversalPrint(root->left, result, height, position - pow(2, total - height), total);
		traversalPrint(root->right, result, height, position + pow(2, total - height), total);
	}

	vector<vector<string>> printTree(TreeNode* root) {
		int height = getHeight(root);
		int width = pow(2, height) - 1;
		vector<vector<string>> result(height, vector<string>(width));
		traversalPrint(root, result, 1, width / 2, height);
		return result;
	}
    
    int getHeight(TreeNode *root){
		return root ? max(getHeight(root->left), getHeight(root->right)) + 1 : 0;
    }
};