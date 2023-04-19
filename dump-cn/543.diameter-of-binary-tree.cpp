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
	/*
		三种可能
		1. 左子树的直径
		2. 右子树的直径
		3. 左子树最长枝长度 + 右子树最长枝长度 + 2
	*/
    int maxDia = INT_MIN;
	int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root);
        return maxDia;
	}
    
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        int int1 = root->left?dfs(root->left)+1:0;
        int int2 = root->right?dfs(root->right)+1:0;
        maxDia = max(int1+int2, maxDia);
        return max(int1, int2);
    }
};