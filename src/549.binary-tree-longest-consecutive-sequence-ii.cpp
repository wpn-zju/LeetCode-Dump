class Solution {
public:
	int result = 0;
	int longestConsecutive(TreeNode* root) {
        traversalLC(root);
        return result;
	}

	pair<int, int> traversalLC(TreeNode* root) {
        if(!root)
            return{0,0};
        pair<int, int> l = traversalLC(root->left);
        pair<int, int> r = traversalLC(root->right);
        pair<int, int> cur = {1,1};
        if(root->left){
            if(root->left->val == root->val + 1)
                cur.first = l.first + 1;
            else if(root->left->val == root->val - 1)
                cur.second = l.second + 1;
        }
        if(root->right){
            if(root->right->val == root->val + 1)
                cur.first = max(cur.first, r.first + 1);
            else if(root->right->val == root->val - 1)
                cur.second = max(cur.second, r.second + 1);
        }
        result = max(result, cur.first + cur.second - 1);
        return cur;
	}
};