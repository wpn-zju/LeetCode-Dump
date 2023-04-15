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
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		return constructFPP(pre, post, 0, pre.size() - 1, 0, pre.size() - 1);
	}

	TreeNode* constructFPP(vector<int>& pre, vector<int>& post, int preIn, int preOut, int postIn, int postOut) {
		if (preIn > preOut)
			return NULL;
		else if (preIn == preOut)
			return new TreeNode(pre[preIn]);
		TreeNode* tn = new TreeNode(pre[preIn]);
		int leftRoot = pre[preIn + 1];
		int leftRootInPostIndex = -1;
		for (int i = postIn; i <= postOut; ++i)
			if (post[i] == leftRoot)
				leftRootInPostIndex = i;
		int leftSubTreeSize = leftRootInPostIndex - postIn + 1;
		int rightSubTreeSize = postOut - leftRootInPostIndex - 1;
		tn->left = constructFPP(pre, post, preIn + 1, preIn + leftSubTreeSize, postIn, postIn + leftSubTreeSize - 1);
		tn->right = constructFPP(pre, post, preOut - rightSubTreeSize + 1, preOut, postOut - rightSubTreeSize, postOut - 1);
		return tn;
	}
};