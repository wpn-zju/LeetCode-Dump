public class Solution {
    public void MoveZeroes(int[] nums)
    {
        if (nums == null || nums.Length == 0)
            return;
        int m = nums.Length;
        int ptr1 = -1;
        int ptr2 = 0;
        while (ptr2 < m)
        {
            if (nums[ptr2] == 0)
            {
                ptr2++;
            }
            else
            {
                ptr1++;
                int tmp = nums[ptr1];
                nums[ptr1] = nums[ptr2];
                nums[ptr2] = tmp;
                ptr2++;
            }
        }
    }
}