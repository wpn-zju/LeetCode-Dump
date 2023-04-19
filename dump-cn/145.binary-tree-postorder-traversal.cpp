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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
	    TreeNode* prev;
	    while (!s.empty() || root != NULL){
		    while (root != NULL){
			    s.push(root);
			    root = root->left;
		    }

		    if (s.top()->right == NULL || s.top()->right == prev){
			    result.push_back(s.top()->val);
			    prev = s.top();
			    s.pop();
			    root = NULL;
		    }
		    else{
			    root = s.top()->right;
		    }
	    }
        
        return result;
    }
};