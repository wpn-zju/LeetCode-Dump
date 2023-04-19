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
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // 理解题意 英文题
        // 该结点是其父节点的右子树 原来的该处结点作为该结点的左子树 必定成立
		TreeNode* newNode = new TreeNode(val);
		if (!root || newNode->val > root->val) {
			newNode->left = root;
			return newNode;
		}
		else {
			TreeNode* tmp = root;
			while (tmp->right && newNode->val < tmp->right->val)
				tmp = tmp->right;
			newNode->left = tmp->right;
			tmp->right = newNode;
			return root;
		}
	}
};