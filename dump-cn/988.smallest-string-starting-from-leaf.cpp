class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string curr;
        return findSmallestString(root, curr);
    }
    string findSmallestString(TreeNode* root, string curr) {
        if(!root)
            return "z";
        curr = string(1, 'a' + root->val) + curr;
        string left = findSmallestString(root->left, curr);
        string right = findSmallestString(root->right, curr);
        return (right == "z") && (left == "z") ? curr : min(left, right);
    }
};