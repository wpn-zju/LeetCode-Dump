public class Solution {
    public uint reverseBits(uint n)
    {
        uint result = 0;
        for (int i = 0; i < 32; ++i)
        {
            result<<=1;
            result+=n&1u;
            n>>=1;
        }
        return result;
    }
}