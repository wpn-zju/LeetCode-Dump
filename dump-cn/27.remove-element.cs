public class Solution {
    public int RemoveElement(int[] nums, int val) {
        if (nums == null || nums.Length == 0)
            return 0;
        int m = nums.Length;
        int ptr1 = -1;
        int ptr2 = 0;
        while(ptr2 < m)
        {
            if(nums[ptr2] == val)
            {
                ptr2++;
            }
            else
            {
                ptr1++;
                nums[ptr1] = nums[ptr2];
                ptr2++;
            }
        }
        return ptr1 + 1;
    }
}