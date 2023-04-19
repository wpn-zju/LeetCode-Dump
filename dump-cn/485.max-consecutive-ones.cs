public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums)
    {
        int max = 0;
        int cur = 0;
        int ptr = 0;
        while(ptr != nums.Length)
        {
            if (nums[ptr] == 1)
                cur++;
            else
                cur = 0;
            if (cur > max)
                max = cur;
            ptr++;
        }
        return max;
    }
}