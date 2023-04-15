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
    vector<double> averageOfLevels(TreeNode* root) {
        return levelOrder1(root);
    }
    
	vector<double> levelOrder1(TreeNode* root) {
        vector<double> result2;
        if (root == NULL)
			return result2;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() != 0)
		{
            vector<double> tempVec;
            int size = myQueue.size();
			while (size--) {
				if (myQueue.front()->right != NULL)
					myQueue.push(myQueue.front()->right);
				if (myQueue.front()->left != NULL)
					myQueue.push(myQueue.front()->left);
                tempVec.push_back(myQueue.front()->val);
				myQueue.pop();
			}
            double sum = 0;
            for(int i = 0;i<tempVec.size();++i){
                sum+=tempVec[i];
            }
            result2.push_back(sum/tempVec.size());
		}
        return result2;
	}
};