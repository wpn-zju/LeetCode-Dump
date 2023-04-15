public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums)
    {
        int max = 0;        // 最大值
        int cur = 0;        // 当前值
        int ptr = 0;        // 前进指针
        int breakPtr = -1;  // 置1断点
        while(ptr != nums.Length)
        {
            if (nums[ptr] == 1)
                cur++;
            else
            {
                if (breakPtr == -1)
                {
                    breakPtr = ptr;
                    cur++;
                }
                else
                {
                    cur = ptr - breakPtr;
                    breakPtr = ptr;
                }
            }
            if (cur > max)
                max = cur;
            ptr++;
        }
        return max;
    }
}