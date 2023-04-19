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
	int maxLevelSum(TreeNode* root) {
		int result = 0;
		int maxValue = INT_MIN;
		int levelCount = 0;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			++levelCount;
			int tmp = 0;
			int size = que.size();
			while (size--) {
				TreeNode* cur = que.front();
				tmp += cur->val;
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
				que.pop();
			}
			if (tmp > maxValue) {
				maxValue = tmp;
				result = levelCount;
			}
		}
		return result;
	}
};