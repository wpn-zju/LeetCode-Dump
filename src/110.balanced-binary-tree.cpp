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
	int maxDepth(TreeNode* root) {
		return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	bool isBalanced(TreeNode* root) {
        // 节点平衡 = 左子节点平衡 && 右子节点平衡 && 左右子树高度差小于等于1
		return root == NULL ? true : isBalanced(root->left) && isBalanced(root->right) && abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
	}
};