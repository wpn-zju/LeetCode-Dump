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
    // O(n) 如果先建立子节点个数树可以降到O(logn)
	int kthSmallest(TreeNode* root, int k) {
		int count = 0;
		stack<TreeNode*> s;
		while (!s.empty() || root != NULL) {
			while (root != NULL) {
				s.push(root);
				root = root->left;
			}

			root = s.top()->right;
			if (++count == k)
				return s.top()->val;
			s.pop();
		}
		return 0;
	}
};