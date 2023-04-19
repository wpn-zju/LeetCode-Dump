public class Solution {
    public int MissingNumber(int[] nums)
    {
        int k = 0;
        for (int i = 1; i < nums.Length + 1; ++i)
            k ^= i;
        foreach (int i in nums)
            k ^= i;
        return k;
    }
}