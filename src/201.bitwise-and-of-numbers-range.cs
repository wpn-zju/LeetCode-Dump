public class Solution {
    public int RangeBitwiseAnd(int m, int n)
    {
        int i = 32;
        while (i-- != 0)
        {
            uint a = (uint)((m >> i) << 31) >> 31;
            uint b = (uint)((n >> i) << 31) >> 31;
            if (a != b)
                break;
        }
        i++;
        return (m >> i) << i;
    }
}