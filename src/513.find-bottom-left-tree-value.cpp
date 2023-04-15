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
	int findBottomLeftValue(TreeNode* root) {
		int result;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() != 0)
		{
			int size = myQueue.size();
			result = myQueue.front()->val;
			while (size--) {
				if (myQueue.front()->left != NULL)
					myQueue.push(myQueue.front()->left);
				if (myQueue.front()->right != NULL)
					myQueue.push(myQueue.front()->right);
				myQueue.pop();
			}
		}
		return result;
	}
};