public class Solution {
    public int RemoveDuplicates(int[] nums)
    {
        if (nums == null || nums.Length == 0)
            return 0;
        int m = nums.Length;
        int ptr1 = 0;
        int ptr2 = 1;
        while(ptr2 < m)
        {
            if(nums[ptr1] == nums[ptr2])
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