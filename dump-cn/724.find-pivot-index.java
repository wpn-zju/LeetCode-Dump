class Solution {
    public int pivotIndex(int[] nums) {
        if (nums.length == 0)
            return -1;
        int sum = 0;
        for (int i = 0; i < nums.length; ++i)
            sum += nums[i];
        int currentSum = 0;
        for(int i = 0; i < nums.length; ++i)
        {
            currentSum += nums[i];
            if (currentSum - nums[i] == sum - currentSum)
                return i;
        }
        return -1;
    }
}