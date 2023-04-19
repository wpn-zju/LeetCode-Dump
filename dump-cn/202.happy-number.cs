public class Solution {
    public bool IsHappy(int n)
    {
        int a = n, b = n;
        do
        {
            if (a == 1 || b == 1 || HappyOut(a) == 1)
                return true;
            a = HappyOut(a);
            b = HappyOut(b);
            b = HappyOut(b);
        } while (a != b);
        return false;
    }
    
    public int HappyOut(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
}