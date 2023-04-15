public class Solution {
    public int HammingWeight(uint n)
    {
        int result = 0;
        while (n != 0)
        {
            result++;
            n &= n - 1;
        }
        return result;
    }
    
    public int HammingDistance(int x, int y) {
        return HammingWeight((uint)(x^y));
    }
}