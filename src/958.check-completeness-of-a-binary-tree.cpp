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
	bool isCompleteTree(TreeNode* root) {
		bool nullFlag = false;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() > 0) {
			if (myQueue.front()->left)
				if (nullFlag)
					return false;
				else
					myQueue.push(myQueue.front()->left);
			else
				nullFlag = true;
			if (myQueue.front()->right)
				if (nullFlag)
					return false;
				else
					myQueue.push(myQueue.front()->right);
			else
				nullFlag = true;
			myQueue.pop();
		}
		return true;
	}
};