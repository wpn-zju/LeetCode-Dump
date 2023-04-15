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
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> vec;
		stack<TreeNode*> s;
		TreeNode *cur = root;
		while (!s.empty() || cur != NULL)
		{
			if (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = s.top();
				s.pop();
				vec.push_back(cur->val);
				cur = cur->right;
			}
		}
		return vec;
	}
};