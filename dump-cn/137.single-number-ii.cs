public class Solution {
    public int SingleNumber(int[] nums)
    {
        int a = 0, b = 0, c = 0;
        foreach(int i in nums)
        {
            b = b | (a & i);
            a = a ^ i;
            c = a & b;
            b = b & ~c;
            a = a & ~c;
        }
        return a;
    }
}