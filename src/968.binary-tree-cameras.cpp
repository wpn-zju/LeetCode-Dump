class Solution {
public:
	int minCameraCover(TreeNode* root) {
		int tag = 0;
		int result = minCameraCover(root, tag);
		return tag == 2 ? result + 1 : result;
	}

	// 0 -> 子树监控
	// 1 -> 自己监控
	// 2 -> 根监控
	int minCameraCover(TreeNode* root, int& tag) {
		if (!root)
			return 0;
		int lTag = 0, rTag = 0;
		int lmcc = minCameraCover(root->left, lTag);
		int rmcc = minCameraCover(root->right, rTag);
		if (!lTag && !rTag) tag = 2;
		else if (lTag == 2 || rTag == 2) tag = 1;
		return lmcc + rmcc + (tag == 1);
	}
};