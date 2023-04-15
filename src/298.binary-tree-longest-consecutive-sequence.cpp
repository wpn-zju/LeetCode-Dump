class Solution {
public:
    int result = 0;
	int longestConsecutive(TreeNode* root) {
        traversalLC(root);
        return result;
	}

	int traversalLC(TreeNode* root) {
        if(!root)
            return 0;
        int l = traversalLC(root->left);
        int r = traversalLC(root->right);
        int maxL = 1;
        if(root->left)
            if(root->left->val == root->val + 1)
                maxL = l + 1;
        if(root->right)
            if(root->right->val == root->val + 1)
                maxL = max(maxL, r + 1);
        result = max(result, maxL);
        return maxL;
	}
};