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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        return constructMaximumBinaryTree_2(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructMaximumBinaryTree_2(vector<int>& nums, int start, int end){
        int maxIndex = findMax(nums, start, end);
        TreeNode* tn = new TreeNode(nums[maxIndex]);
        if(start!=maxIndex)
            tn->left = constructMaximumBinaryTree_2(nums, start, maxIndex-1);
        if(end!=maxIndex)
            tn->right = constructMaximumBinaryTree_2(nums, maxIndex+1, end);
        return tn;
    }
    
    int findMax(vector<int>& nums, int start, int end){
        int max = INT_MIN;
        int maxIndex = 0;
        for(int i =start;i<=end;++i){
            if(nums[i]>max){
                max = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};