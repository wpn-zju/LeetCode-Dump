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
	unordered_map<int, int> sumMap;
	bool checkEqualTree(TreeNode* root) {
		int sum = sumTree(root);
		int count = sumMap[sum >> 1];
		return sum ? !(sum & 1) && count : count > 1;
	}

	int sumTree(TreeNode* root) {
		if (!root)
			return 0;
		int sum = sumTree(root->left) + sumTree(root->right) + root->val;
		sumMap[sum]++;
		return sum;
	}
};