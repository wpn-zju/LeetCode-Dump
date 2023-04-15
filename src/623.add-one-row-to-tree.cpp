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
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1 || d == 0) {
			TreeNode* tn = new TreeNode(v);
			if(d==1)
            tn->left = root;
            else if(d==0)
                tn->right = root;
			return tn;
		}
        if(root!=NULL){
            root->left = addOneRow(root->left, v, d>2?d - 1:1);
		    root->right = addOneRow(root->right, v, d>2?d - 1:0);
        }
		return root;
	}
};