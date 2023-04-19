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
	vector<int> largestValues(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return result;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() != 0)
		{
			int size = myQueue.size();
			int max = INT_MIN;
			while (size--) {
				if (myQueue.front()->left != NULL)
					myQueue.push(myQueue.front()->left);
				if (myQueue.front()->right != NULL)
					myQueue.push(myQueue.front()->right);
				if (myQueue.front()->val > max)
					max = myQueue.front()->val;
				myQueue.pop();
			}
			result.push_back(max);
		}
		return result;
	}
};