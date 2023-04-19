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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> vec;
		if (root == NULL)
			return vec;
		vector<int>* vecP = new vector<int>();
		queue<TreeNode*> myQueue;
		queue<int> depthQueue;
		myQueue.push(root);
		depthQueue.push(1);
		int tempDepth = 1;
		while (myQueue.size() != 0)
		{
			vecP->push_back(myQueue.front()->val);
			if (myQueue.front()->left != NULL)
			{
				myQueue.push(myQueue.front()->left);
				depthQueue.push(depthQueue.front() + 1);
			}
			if (myQueue.front()->right != NULL)
			{
				myQueue.push(myQueue.front()->right);
				depthQueue.push(depthQueue.front() + 1);
			}
			depthQueue.pop();
			myQueue.pop();
			if (depthQueue.size() == 0 || tempDepth != depthQueue.front())
			{
				tempDepth++;
				vec.push_back(*vecP);
				vecP = new vector<int>();
			}
		}
		reverse(vec.begin(), vec.end());
		return vec;
	}
};