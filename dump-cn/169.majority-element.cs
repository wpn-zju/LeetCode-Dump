public class Solution {
    public int MajorityElement(int[] nums)
    {
        int count = 1;
        int curN = nums[0];
        for(int i = 1; i < nums.Length; ++i)
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