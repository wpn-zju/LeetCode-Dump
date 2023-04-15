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
    vector<int> result;

    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return result;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			root = s.top();
			result.push_back(root->val);
			s.pop();
			if (root->right)
				s.push(root->right);
			if (root->left)
				s.push(root->left);
		}
        
        return result;
    }
};