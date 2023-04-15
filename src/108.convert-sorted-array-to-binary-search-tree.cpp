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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end)
	{
        TreeNode* node = NULL;
		if (end >= start){
            int mid = start + (end - start >> 1);
		    node = new TreeNode(nums[mid]);
		    node->left = sortedArrayToBST(nums, start, mid - 1);
		    node->right = sortedArrayToBST(nums, mid + 1, end);
        }
		return node;
	}
};