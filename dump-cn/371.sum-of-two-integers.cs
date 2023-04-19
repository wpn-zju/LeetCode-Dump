public class Solution {
    public int GetSum(int a, int b)
    {
        int sum = a ^ b, carry = (int)((uint)(a & b) << 1);
        return carry == 0 ? sum : GetSum(sum, carry);
    }
}