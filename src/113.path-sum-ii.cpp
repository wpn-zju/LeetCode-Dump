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
	vector<vector<int>> result1;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return result1;
		vector<int> vec;
		dfs2(root, sum, vec);
		return result1;
	}

	void dfs2(TreeNode* root, int target, vector<int> vec) {
		vec.push_back(root->val);
		if (root->left == NULL && root->right == NULL) {
			if (root->val == target) {
				result1.push_back(vec);
			}
			vec.pop_back();
		}
		else {
			if (root->left != NULL) {
				dfs2(root->left, target - root->val, vec);
			}
			if (root->right != NULL) {
				dfs2(root->right, target - root->val, vec);
			}
		}
	}
};