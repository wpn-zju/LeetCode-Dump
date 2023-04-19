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
	double maxAve = DBL_MIN;
	double maximumAverageSubtree(TreeNode* root) {
		int tmp = 0;
		sumTraversal(root, tmp);
		return maxAve;
	}

	int sumTraversal(TreeNode* root, int& count) {
		if (!root)
			return 0;
		int countL = 0;
		int countR = 0;
		int sumL = sumTraversal(root->left, countL);
		int sumR = sumTraversal(root->right, countR);
		count = countL + countR + 1;
		int curSum = sumL + sumR + root->val;
		if ((double)curSum / count > maxAve)
			maxAve = (double)curSum / count;
		return curSum;
	}
};