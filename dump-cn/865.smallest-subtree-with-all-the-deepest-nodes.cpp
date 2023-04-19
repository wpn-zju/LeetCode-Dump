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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = 0;
        return dfsDK(root, depth);
    }
    
    TreeNode* dfsDK(TreeNode* root, int& depth){
        if(!root){
            depth = 0;
            return nullptr;
        }
        
        int depthL = depth + 1;
        int depthR = depth + 1;
        TreeNode* leftN = dfsDK(root->left, depthL);
        TreeNode* rightN = dfsDK(root->right, depthR);
        if(depthL > depthR){
            depth = ++depthL;
            return leftN;
        }
        else if(depthL < depthR){
            depth = ++depthR;
            return rightN;
        }
        else{
            depth = ++depthL;
            return root; 
        }
    }
};