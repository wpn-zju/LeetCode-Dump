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
	vector<vector<int>> levelOrder(TreeNode* root) {
		levelOrder2(root);
        return result;
	}
    
	vector<vector<int>> result;
	void levelOrder2(TreeNode* root) {
		if (root == NULL)
			return;
		vector<int>* vecP = new vector<int>();
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() != 0)
		{
			int size = myQueue.size();
			while (size--) {
				vecP->push_back(myQueue.front()->val);
				if (myQueue.front()->left != NULL)
					myQueue.push(myQueue.front()->left);
				if (myQueue.front()->right != NULL)
					myQueue.push(myQueue.front()->right);
				myQueue.pop();
			}
			result.push_back(*vecP);
			vecP = new vector<int>();
		}
	}};