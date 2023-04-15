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
	vector<int> result2;
	void levelOrder1(TreeNode* root) {
		if (root == NULL)
			return;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() != 0)
		{
            int size = myQueue.size();
			result2.push_back(myQueue.front()->val);
			while (size--) {
				if (myQueue.front()->right != NULL)
					myQueue.push(myQueue.front()->right);
				if (myQueue.front()->left != NULL)
					myQueue.push(myQueue.front()->left);
				myQueue.pop();
			}
		}
	}

	vector<int> rightSideView(TreeNode* root) {
		levelOrder1(root);
		return result2;
	}
};