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
	int disCount = 0;
	bool findDK = false;
	vector<int> disCountResult;
	TreeNode* targetTN = nullptr;
	int dfsDK(TreeNode* root) {
		if (root == nullptr)
			return -1;
		else if (root == targetTN) {
			addSubTreeAns(root, disCount);
			return 1;
		}

		int leftDis = dfsDK(root->left);	// 左子树到目标结点距离
		int rightDis = dfsDK(root->right);	// 右子树到目标结点距离

		if (leftDis != -1) {
			if (leftDis == disCount)
				disCountResult.push_back(root->val);
			else
				addSubTreeAns(root->right, disCount - leftDis - 1);
			return leftDis + 1;
		}
		else if (rightDis != -1) {
			if (rightDis == disCount)
				disCountResult.push_back(root->val);
			else
				addSubTreeAns(root->left, disCount - rightDis - 1);
			return rightDis + 1;
		}
		return -1;
	}

	void addSubTreeAns(TreeNode* root, int dis) {
		if (!root)
			return;
		if (!dis)
			disCountResult.push_back(root->val);
		addSubTreeAns(root->left, dis - 1);
		addSubTreeAns(root->right, dis - 1);
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		disCount = K;
		targetTN = target;
		dfsDK(root);
		return disCountResult;
	}
};