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
    vector<int> vec;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL || (root->left==NULL && root->right == NULL))
            return false;
        inorder(root);
        int i = 0;
        int j = vec.size()-1;
        while(i!=j){
            if(vec[i]+vec[j]==k)
                return true;
            else if(vec[i]+vec[j]<k)
                i++;
            else
                j--;
        }
        return false;
    }
    
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
};