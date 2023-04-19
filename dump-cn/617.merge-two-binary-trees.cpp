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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL && t2 == NULL)
            return NULL;
        else if(t1!=NULL && t2==NULL){
            t1->left = mergeTrees(t1->left, NULL);
            t1->right = mergeTrees(t1->right, NULL);
            return t1;
        }
        else if(t1  ==NULL && t2!=NULL){
            TreeNode* newTn;
            newTn = new TreeNode(t2->val);
            newTn->left = mergeTrees(newTn->left, t2->left);
            newTn->right = mergeTrees(newTn->right, t2->right);
            return newTn;
        }
        else{
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
            t1->val += t2->val;
            return t1;
        }
    }
};