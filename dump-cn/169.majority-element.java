class Solution {
    public int majorityElement(int[] nums) {
        int count = 1;
        int curN = nums[0];
        for(int i = 1; i < nums.length; ++i)
        {
            if (nums[i] == curN)
                count++;
            else
                count--;
            if (count < 0)
            {
                count = 1;
                curN = nums[i];
            }
        }
        return curN;
    }
}