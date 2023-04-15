public class Solution {
    public int PivotIndex(int[] nums)
    {
        if (nums.Length == 0)
            return -1;
        int sum = 0;
        for (int i = 0; i < nums.Length; ++i)
            sum += nums[i];
        int currentSum = 0;
        for(int i = 0; i < nums.Length; ++i)
        {
            currentSum += nums[i];
            if (currentSum - nums[i] == sum - currentSum)
                return i;
        }
        return -1;
    }
}