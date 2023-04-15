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
	string result_11 = "";
	string tree2str(TreeNode* t) {
		preorder_1(t);
		return result_11;
	}

	void preorder_1(TreeNode* t) {
		if (t == NULL)
			return;
		result_11 += to_string(t->val);

		if (t->left != NULL) {
			result_11 += '(';
			preorder_1(t->left);
			result_11 += ')';

			if (t->right != NULL) {
				result_11 += '(';
				preorder_1(t->right);
				result_11 += ')';
			}
		}
		else if (t->right != NULL) {
			result_11 += "()";
			result_11 += '(';
			preorder_1(t->right);
			result_11 += ')';
		}
	}
};