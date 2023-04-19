class Solution {
    public int[] findErrorNums(int[] nums) {
                int duplicatedNum = 0;
        for(int i = 0;i<nums.length;++i)
            if (nums[Math.abs(nums[i]) - 1] < 0)
                duplicatedNum = Math.abs(nums[i]);
            else
                nums[Math.abs(nums[i]) - 1] *= -1;
        int c = 0;
        for(int i = 0;i<nums.length;++i)
            c ^= Math.abs(nums[i]);
        c ^= duplicatedNum;
        for (int i = 1; i <= nums.length; ++i)
            c ^= i;
        return new int[] { duplicatedNum, c };
    }
}