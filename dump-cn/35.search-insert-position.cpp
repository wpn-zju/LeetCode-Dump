class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ptr1 = -1;
        int ptr2 = nums.size();
        int x = (ptr1 + ptr2) / 2;
        while(nums[x] != target && ptr1 < ptr2 - 1){
            if(nums[x] > target)
                ptr2 = x;
            else
                ptr1 = x;
            x = (ptr1 + ptr2) / 2;
        }
        return nums[x] == target ? x : ptr2;
    }
};