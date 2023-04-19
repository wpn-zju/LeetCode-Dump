class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int cur = 0;
        int ptr = 0;
        while(ptr != nums.length)
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