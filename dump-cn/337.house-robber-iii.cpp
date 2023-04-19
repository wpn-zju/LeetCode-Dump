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
    unordered_map<TreeNode *, int> sums;
public:
    int rob(TreeNode* root) {
        return tryRob(root);
    }
    
    int tryRob(TreeNode* node) {
        if (!node) return 0;
        if (sums.count(node)) return sums[node];
        //偷取该节点
        int res1 = 0;
        if (node->left) {
            res1 += (tryRob(node->left->left) + tryRob(node->left->right));
        }
        if (node->right) {
            res1 += (tryRob(node->right->left) + tryRob(node->right->right));
        }
        res1 += node->val;
        //不偷取该节点
        int res2 = tryRob(node->left) + tryRob(node->right);
        sums[node] = max(res1, res2);
        return sums[node];
    }
};
