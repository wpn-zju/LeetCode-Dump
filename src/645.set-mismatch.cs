public class Solution {
    public int[] FindErrorNums(int[] nums)
    {
        int duplicatedNum = 0;
        for(int i = 0;i<nums.Length;++i)
            if (nums[Math.Abs(nums[i]) - 1] < 0)
                duplicatedNum = Math.Abs(nums[i]);
            else
                nums[Math.Abs(nums[i]) - 1] *= -1;
        int c = 0;
        for(int i = 0;i<nums.Length;++i)
            c ^= Math.Abs(nums[i]);
        c ^= duplicatedNum;
        for (int i = 1; i <= nums.Length; ++i)
            c ^= i;
        return new int[2] { duplicatedNum, c };
    }
}