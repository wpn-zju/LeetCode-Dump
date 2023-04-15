public class Solution {
    public int[] SingleNumber(int[] nums)
    {
        int a = 0;
        foreach (int i in nums)
            a ^= i;
        // assume x and y are two elements appear once, now a = x ^ y
        int index = 0;
        for (index = 0; index < 32; ++index)
        {
            uint temp = (uint)a;
            temp >>= index;
            temp <<= 31;
            temp >>= 31;
            if (temp == 1)
                break;
        }
        int b = 0, c = 0;
        foreach(int i in nums)
        {
            uint temp = (uint)i;
            temp >>= index;
            temp <<= 31;
            temp >>= 31;
            if (temp == 0)
                b ^= i;
            else
                c ^= i;
        }
        return new int[] { b, c };
    }
}