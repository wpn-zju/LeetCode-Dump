class Solution {
public:
	void traversalBGWM(TreeNode* root, vector<int>& output, int target) {
		if (!root)
			return;
		if (root->val == target) {
			countBGWM(root->left, output[0]);
			countBGWM(root->right, output[1]);
		}
		else {
			traversalBGWM(root->left, output, target);
			traversalBGWM(root->right, output, target);
		}
	}

	void countBGWM(TreeNode* root, int& count) {
		if (!root)
			return;
		count++;
		countBGWM(root->left, count);
		countBGWM(root->right, count);
	}

	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		vector<int> output(2, 0);
		traversalBGWM(root, output, x);
		return 2 * output[0] > n || 2 * output[1] > n || 2 * (output[0] + output[1] + 1) < n;
	}
};