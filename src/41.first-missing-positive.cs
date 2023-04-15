public class Solution {
    public void Swap(ref int a, ref int b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    public int FirstMissingPositive(int[] nums)
    {
        for (int i = 0; i < nums.Length;)
                if (nums[i] > 0 && nums[i] < nums.Length&&nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
                    Swap(ref nums[nums[i] - 1], ref nums[i]);
                else
                    i++;
        for (int i = 0; i < nums.Length; ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return nums.Length + 1;
    }
}